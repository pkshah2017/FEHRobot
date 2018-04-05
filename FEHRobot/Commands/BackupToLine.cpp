#include "BackupToLine.h"
#include <FEHUtility.h>

BackupToLine::BackupToLine(Robot *robot_, int power_)
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

StatusCode BackupToLine::changePower(int newPower){
    power = newPower;
    return Success;
}

StatusCode BackupToLine::initialize() {
    StatusCode status = updateLineFollowerState(2.5f, 2.2f, 1.5f);
    startTime = TimeNow();
    LCD.Clear();
    LCD.WriteRC("Start Time: ", 1, 1);
    LCD.WriteRC("Elaps Time: ", 2, 1);
    LCD.WriteRC("Timeout: ", 3, 1);
    return status;
}

StatusCode BackupToLine::run() {
    StatusCode status = updateLineFollowerState(2.5f, 2.2f, 1.5f);

    LCD.WriteRC(TimeNow(), 1, 13);
    LCD.WriteRC(TimeNow() - startTime , 2, 13);
    LCD.WriteRC(BACKUP_TIMEOUT, 3, 9);
    if(TimeNow() - startTime >= BACKUP_TIMEOUT){
        return E_Timeout;
    }
    if(status == Success){
        switch(lineFollowStatus){
        case OFF_ON_OFF:
            //Should never happen
            return E_UnreachableCode;
            break;
        case ON_ON_OFF:
            (*robot).stop();
            break;
        case ON_OFF_OFF:
            (*robot).driveAndTurn(274, 27, -15);
            //   .turn(-25);
            break;
        case OFF_ON_ON:
            return E_UnreachableCode;
            break;
        case OFF_OFF_ON:
            return E_UnreachableCode;
            break;
        case OFF_OFF_OFF:
            (*robot).drive(180, power);
            break;
        }
    }

    return status;
}

bool BackupToLine::isFinished() {
    return lineFollowStatus == ON_ON_OFF ;
}

StatusCode BackupToLine::completion(){
    (*robot).stop();

    return Success;
}

StatusCode BackupToLine::updateLineFollowerState(float leftThreshold, float centerThreshold, float rightTheshold){
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

const char * BackupToLine::getCommandName(){
    return "BackupToLine";
}
