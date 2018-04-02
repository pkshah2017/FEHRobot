#include "Logger.h"
#include "BackupToLineSingleOpto.h"
#include <FEHUtility.h>

BackupToLineSingleOpto::BackupToLineSingleOpto(Robot *robot_, int power_)
{
    robot = robot_;
    StatusCode status = changePower(power_);
    if(status != Success){
        logger->logError(status);
        LCD.Write("ERROR CODE: ");
        LCD.WriteLine((int)status);
        LCD.Write("Description: ");
        //LCD.WriteLine(errordesc[(int)status].message);
    }
}

StatusCode BackupToLineSingleOpto::changePower(int newPower){
    power = newPower;
    return Success;
}

StatusCode BackupToLineSingleOpto::initialize() {
    StatusCode status = updateLineFollowerState(2.6f);

    return status;
}

StatusCode BackupToLineSingleOpto::run() {
    StatusCode status = updateLineFollowerState(2.6f);

    if(status == Success){
        if(!onLine){
            robot->drive(180, power);
        }
    }
    return status;
}

bool BackupToLineSingleOpto::isFinished() {
    return onLine;
}

StatusCode BackupToLineSingleOpto::completion(){
    (*robot).stop();

    return Success;
}

StatusCode BackupToLineSingleOpto::updateLineFollowerState(float optoThreshold){
    (*robot).updateSensorStates();

    float opto = (*robot).getOpto(CornerOpto);
    LCD.WriteRC("Corner Opto: ", 1, 1);
    LCD.WriteRC(opto, 1, 13);
    LCD.WriteRC("Threshold: ", 2, 1);
    LCD.WriteRC(optoThreshold, 2, 13);
    onLine = opto > optoThreshold;

    return Success;
}

const char * BackupToLineSingleOpto::getCommandName(){
    return "BackupToLineSingleOpto";
}
