#include "DriveToPosition.h"
#include <FEHUtility.h>
#include <math.h>
#include <FEHLCD.h>

DriveToPosition::DriveToPosition(Robot &robot_, float x_, float y_)
{
    robot = robot_;
    StatusCode status = setup(x_, y_);
    if(status != Success){
        LCD.Write("ERROR CODE: ");
        LCD.WriteLine((int)status);
        LCD.Write("Description: ");
        //LCD.WriteLine(errordesc[(int)status].message);
    }
}

StatusCode DriveToPosition::setup(float newX, float newY){
    StatusCode status = changeXSetpoint(newX);
    if(status == Success){
        status = changeYSetpoint(newY);
    }
    return status;
}

StatusCode DriveToPosition::changeXSetpoint(float x_){
    x = x_;
    return Success;
}

StatusCode DriveToPosition::changeYSetpoint(float y_){
    y = y_;
    return Success;
}

StatusCode DriveToPosition::initialize() {
    robot.updateRPSStates();
    currentX = robot.getX();
    currentY = robot.getY();

    return Success;
}

StatusCode DriveToPosition::run() {
    robot.updateRPSStates();
    currentX = robot.getX();
    currentY = robot.getY();
    float currentHeading = robot.getHeading();

    float deltaX = x - currentX;
    float deltaY = y - currentY;

    float error = sqrt(deltaX * deltaX + deltaY * deltaY);
    float heading = atan(deltaY/deltaX) * 180 / PI;
    heading = ((int)(heading - currentHeading + 360)) % 360;
    if(deltaX < 0 && deltaY > 0){
        heading = 180 + heading;
    } else if(deltaX < 0 && deltaY < 0){
        heading = 180 + heading;
    } else if (deltaX > 0 && deltaY < 0){
        heading += 360;
    }
    heading += 90;

    robot.drive(heading, 30);

    return Success;
}

bool DriveToPosition::isFinished() {
    robot.updateRPSStates();
    float deltaX = x - currentX;
    float deltaY = y - currentY;

    float error = sqrt(deltaX * deltaX + deltaY * deltaY);

    return abs(error) <= POSITION_TOLERANCE;
}

StatusCode DriveToPosition::completion(){
    robot.stop();

    return Success;
}
