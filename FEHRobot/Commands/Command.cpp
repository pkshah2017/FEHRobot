#include "Logger.h"
#include "Command.h"
#include <FEHUtility.h>
#include <FEHLCD.h>

Command::Command()
{
}

StatusCode Command::execute() {
    StatusCode errorCode = initialize();
    if(errorCode != Success){
        errorCode = initializeFailureRecovery(errorCode);
    }
    while (errorCode == Success && !isFinished()) {
        logger.logWorldState();
        StatusCode errorCode = run();
        if(errorCode != Success){
            //logger.printError(errorCode);
            errorCode = runFailureRecovery(errorCode);
        }
		Sleep(REFRESH_RATE);
	}
    errorCode = completion();
    return errorCode;
}

StatusCode Command::initializeFailureRecovery(StatusCode errorCode){
    return printError(errorCode);
}

StatusCode Command::runFailureRecovery(StatusCode errorCode){
    return printError(errorCode);
}

StatusCode Command::printError(StatusCode errorCode){
    LCD.Write("ERROR CODE: ");
    LCD.WriteLine((int)errorCode);
    LCD.Write("Description: ");
    //LCD.WriteLine((errordesc[(int)errorCode]));
    return errorCode;
}
