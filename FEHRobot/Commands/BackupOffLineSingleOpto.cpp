#include "Logger.h"
#include "BackupOffLineSingleOpto.h"
#include <FEHUtility.h>

BackupOffLineSingleOpto::BackupOffLineSingleOpto(Robot *robot_, int power_)
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

StatusCode BackupOffLineSingleOpto::changePower(int newPower){
    power = newPower;
    return Success;
}

StatusCode BackupOffLineSingleOpto::initialize() {
    StatusCode status = updateLineFollowerState(2.5f);

    return status;
}

StatusCode BackupOffLineSingleOpto::run() {
    StatusCode status = updateLineFollowerState(2.5f);

    if(status == Success){
        robot->drive(180, power);
    }
    return status;
}

bool BackupOffLineSingleOpto::isFinished() {
    return !onLine;
}

StatusCode BackupOffLineSingleOpto::completion(){
    (*robot).stop();

    return Success;
}

StatusCode BackupOffLineSingleOpto::updateLineFollowerState(float optoThreshold){
    (*robot).updateSensorStates();

    float opto = (*robot).getOpto(CornerOpto);
    onLine = opto > optoThreshold;

    return Success;
}

const char * BackupOffLineSingleOpto::getCommandName(){
    return "BackupOffLineSingleOpto";
}
