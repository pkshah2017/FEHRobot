#include "Logger.h"
#include "BackupToLineSingleOpto.h"
#include <FEHUtility.h>

BackupToLineSingleOpto::BackupToLineSingleOpto(Robot *robot_, int power_)
{
    robot = robot_;
    StatusCode status = changePower(power_);
    startTime = 0.0f;
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
    StatusCode status = updateLineFollowerState(2.64f);
    startTime = TimeNow();
    return status;
}

StatusCode BackupToLineSingleOpto::run() {
    StatusCode status = updateLineFollowerState(2.64f);

    if(TimeNow() - startTime >= BACKUP_SINGLE_OPTO_TIMEOUT){
        LCD.WriteLine("BTLSO has failed");
        logger->logMessage("BackupToLineSingleOpto run has timed out");
        return E_Timeout;
    }

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
