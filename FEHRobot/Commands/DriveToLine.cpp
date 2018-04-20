/*
 * This command makes the robot backup until center set of optos is over black line.
 * This command is used in the DriveToGarage Task.
*/
#include "Logger.h"
#include "DriveToLine.h"
#include <FEHUtility.h>

DriveToLine::DriveToLine(Robot *robot_, int power_)
{
    robot = robot_;
    StatusCode status = changePower(power_);
    startTime = 0.0f;
    if(status != Success){
        LCD.Write("ERROR CODE: ");
        LCD.WriteLine((int)status);
        LCD.Write("Description: ");
        //LCD.WriteLine(errordesc[(int)status].message);
    }
}

StatusCode DriveToLine::changePower(int newPower){
    power = newPower;
    return Success;
}

StatusCode DriveToLine::initialize() {
    StatusCode status = updateLineFollowerState(2.65, 2.2, 2.1);
    startTime = TimeNow();
    LCD.Clear();
    return status;
}

StatusCode DriveToLine::run() {
    StatusCode status = updateLineFollowerState(2.65, 2.2, 2.1);

    if(TimeNow() - startTime >= BACKUP_TIMEOUT){
        LCD.WriteLine("DTL has failed");
        logger->logMessage("DriveToLine run has timed out");
        return E_Timeout;
    }
    if(status == Success){
        switch(lineFollowStatus){
        case OFF_ON_OFF:
            //Should never happen
            return E_UnreachableCode;
            break;
        case ON_ON_OFF:
            (*robot).turn(-25);
            break;
        case ON_OFF_OFF:
            (*robot).turn(-25);
            break;
        case OFF_ON_ON:
            (*robot).turn(25);
            break;
        case OFF_OFF_ON:
            (*robot).turn(25);
            break;
        case OFF_OFF_OFF:
            (*robot).drive(180, power);
            break;
        }
    }
    return status;
}

bool DriveToLine::isFinished() {
    return lineFollowStatus == ON_ON_ON;
}

StatusCode DriveToLine::completion(){
    (*robot).stop();

    return Success;
}

StatusCode DriveToLine::updateLineFollowerState(float leftThreshold, float centerThreshold, float rightTheshold){
    (*robot).updateSensorStates();

    float left = (*robot).getOpto(LeftOpto);
    float center = (*robot).getOpto(CenterOpto);
    float right = (*robot).getOpto(RightOpto);

    //   > is black (on)     < is white (off)
    if (right < rightTheshold && center > centerThreshold && left < leftThreshold) {
        lineFollowStatus = OFF_ON_OFF; // update a new state
    }
    else if (right < rightTheshold && center > centerThreshold && left > leftThreshold) {
        lineFollowStatus = OFF_ON_ON; // update a new state
    }
    else if (right < rightTheshold &&  center < centerThreshold && left > leftThreshold) {
        lineFollowStatus = OFF_OFF_ON; // update a new state
    }
    else if (right > rightTheshold && center > centerThreshold && left < leftThreshold) {
        lineFollowStatus = ON_ON_OFF; // update a new state
    }
    else if (right > rightTheshold && center < centerThreshold && left < leftThreshold) {
        lineFollowStatus = ON_OFF_OFF; // update a new state
    }
    else if (right < rightTheshold && center < centerThreshold && left < leftThreshold)
    {
        lineFollowStatus = OFF_OFF_OFF;
    }
    else
    {
        lineFollowStatus = ON_ON_ON;
    }
    return Success;
}

const char * DriveToLine::getCommandName(){
    return "DriveToLine";
}
