#include "BackupToWhiteLine.h"
#include <FEHUtility.h>

BackupToWhiteLine::BackupToWhiteLine(Robot *robot_, int power_)
{
    robot = robot_;
    StatusCode status = changePower(power_);
    if(status != Success){
        LCD.Write("ERROR CODE: ");
        LCD.WriteLine((int)status);
        LCD.Write("Description: ");
        //LCD.WriteLine(errordesc[(int)status].message);
    }
}

StatusCode BackupToWhiteLine::changePower(int newPower){
    power = newPower;
    return Success;
}

StatusCode BackupToWhiteLine::initialize() {
    StatusCode status = updateLineFollowerState(2.4f, 2.2f, 1.7f);

    return status;
}

StatusCode BackupToWhiteLine::run() {
    StatusCode status = updateLineFollowerState(2.4f, 2.2f, 1.7f);

    if(status == Success){
        switch(lineFollowStatus){
        case ON_ON_ON:
            (*robot).stop();
            break;
        case ON_ON_OFF:
            (*robot).drive(180, power);
            break;
        case ON_OFF_ON:
            (*robot).drive(180, power);
            break;
        case ON_OFF_OFF:
            (*robot).drive(180, power);
            break;
        case OFF_ON_ON:
            (*robot).drive(180, power);
            break;
        case OFF_ON_OFF:
            (*robot).drive(180, power);
            break;
        case OFF_OFF_ON:
            (*robot).drive(180, power);
            break;
        case OFF_OFF_OFF:
            (*robot).drive(180, power);
            break;
        }
    }
    return status;
}

bool BackupToWhiteLine::isFinished() {
    return lineFollowStatus == ON_ON_ON;
}

StatusCode BackupToWhiteLine::completion(){
    (*robot).stop();

    return Success;
}

StatusCode BackupToWhiteLine::updateLineFollowerState(float leftThreshold, float centerThreshold, float rightTheshold){
    (*robot).updateSensorStates();

    float left = (*robot).getOpto(LeftOpto);
    float center = (*robot).getOpto(CenterOpto);
    float right = (*robot).getOpto(RightOpto);

    //   > is black (off)     < is white (on)
    if (right < rightTheshold && center > centerThreshold && left < leftThreshold) {
        lineFollowStatus = ON_OFF_ON; // update a new state
    }
    else if (right < rightTheshold && center > centerThreshold && left > leftThreshold) {
        lineFollowStatus = ON_OFF_OFF; // update a new state
    }
    else if (right < rightTheshold && center < centerThreshold && left < leftThreshold)
    {
        lineFollowStatus = ON_ON_ON;
    }
    else if (right < rightTheshold &&  center < centerThreshold && left > leftThreshold) {
        lineFollowStatus = ON_ON_OFF; // update a new state
    }
    else if (right > rightTheshold && center < centerThreshold && left < leftThreshold) {
        lineFollowStatus = OFF_ON_ON; // update a new state
    }
    else if (right > rightTheshold && center < centerThreshold && left > leftThreshold) {
        lineFollowStatus = OFF_ON_OFF; // update a new state
    }
    else if (right > rightTheshold && center > centerThreshold && left < leftThreshold) {
        lineFollowStatus = OFF_OFF_ON; // update a new state
    }
    else
    {
        lineFollowStatus = OFF_OFF_OFF;
    }
    return Success;
}

const char * BackupToWhiteLine::getCommandName(){
    return "BackupToWhiteLine";
}
