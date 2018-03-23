#include "DriveToPositionWithHeading.h"
#include <FEHUtility.h>
#include <math.h>
#include <FEHLCD.h>

DriveToPositionWithHeading::DriveToPositionWithHeading(Robot *robot_, float x_, float y_, float heading_)
{
    robot = robot_;
    StatusCode status = setup(x_, y_, heading_);
    if(status != Success){
        LCD.Write("ERROR CODE: ");
        LCD.WriteLine((int)status);
        LCD.Write("Description: ");
        //LCD.WriteLine(errordesc[(int)status].message);
    }
}

StatusCode DriveToPositionWithHeading::setup(float newX, float newY, float newHeading){
    StatusCode status = changeXSetpoint(newX);
    if(status == Success){
        status = changeYSetpoint(newY);
    }
    if(status == Success){
        status = changeHeadingSetpoint(newHeading);
    }
    return status;
}

StatusCode DriveToPositionWithHeading::changeXSetpoint(float x_){
    x = x_;
    return Success;
}

StatusCode DriveToPositionWithHeading::changeYSetpoint(float y_){
    y = y_;
    return Success;
}

StatusCode DriveToPositionWithHeading::changeHeadingSetpoint(float heading_){
    finalHeading = heading_;
    return Success;
}

StatusCode DriveToPositionWithHeading::initialize() {
    (*robot).updateRPSStates();
    currentX = (*robot).getX();
    currentY = (*robot).getY();
    currentHeading = (*robot).getHeading();
    startTime = TimeNow();

    return Success;
}

StatusCode DriveToPositionWithHeading::run() {
    (*robot).updateRPSStates();
    currentX = (*robot).getX();
    currentY = (*robot).getY();
    currentHeading = (*robot).getHeading();

    float deltaX = x - currentX;
    float deltaY = y - currentY;


    //    motor[FL] = -C1LY - C1LX - C1RX;
    //    motor[FR] =  C1LY - C1LX - C1RX;
    //    motor[BR] =  C1LY + C1LX - C1RX;
    //    motor[BL] = -C1LY + C1LX - C1RX;

    float error = sqrt(deltaX * deltaX + deltaY * deltaY);

    /*
     * Calculate what direction to drive in
     */
    float driveHeading = atan(deltaY/deltaX) * 180 / PI;
    driveHeading = ((int)(driveHeading - currentHeading + 360)) % 360;
    if(deltaX < 0 && deltaY > 0){
        driveHeading = 180 + driveHeading;
    } else if(deltaX < 0 && deltaY < 0){
        driveHeading = 180 + driveHeading;
    } else if (deltaX > 0 && deltaY < 0){
        driveHeading += 360;
    }
    driveHeading += 90;

    /*
     * Calculate turn speed
     */
    int tempFinalHeading = (int)(finalHeading+ 180) % 360;
    int tempCurrentHeading = (int)(currentHeading+ 180) % 360;
    float turnSpeed = 0.0f;
    if ((tempFinalHeading - tempCurrentHeading) >= 1){
        turnSpeed = -(float)(.5f*abs((float)(tempFinalHeading - tempCurrentHeading)));
    }
    else if ((tempFinalHeading - tempCurrentHeading) <= -1){
        turnSpeed = (float)(.5f*abs((float)(tempFinalHeading - tempCurrentHeading)));
    }
    else {
        turnSpeed = 0.0f;
    }
    LCD.WriteRC("turn",4,1);
    LCD.WriteRC(turnSpeed,4,9);
    LCD.WriteRC("error",5,1);
    LCD.WriteRC(error,5,9);
    float currentTime = TimeNow();
    LCD.WriteRC("time",6,1);
    LCD.WriteRC(currentTime - startTime,6,9);
    LCD.WriteRC("finalH",7,1);
    LCD.WriteRC(tempFinalHeading,7,9);
    LCD.WriteRC("currentH",7,1);
    LCD.WriteRC(tempCurrentHeading,8,9);

    startTime = currentTime;
    //= (float)(((int)(finalHeading - currentHeading + 360)) % 360)/360.0f;
    (*robot).driveAndTurn(driveHeading, 30, turnSpeed);

    return Success;
}

bool DriveToPositionWithHeading::isFinished() {
    float deltaX = x - currentX;
    float deltaY = y - currentY;

    float positionError = sqrt(deltaX * deltaX + deltaY * deltaY);
    float headingError = abs(currentHeading - finalHeading);

    return abs(positionError) <= POSITION_TOLERANCE;
}

StatusCode DriveToPositionWithHeading::completion(){
    (*robot).stop();

    return Success;
}
