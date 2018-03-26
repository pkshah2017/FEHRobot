#include "Logger.h"
#include "Command.h"
#include <FEHUtility.h>
#include <FEHLCD.h>
#include <typeinfo>

Command::Command()
{
}

StatusCode Command::execute() {
    logger -> logMessage("Beginning Command: ");
    logger -> logMessage(getCommandName());
    logger -> logMessage("\r\n\r\n");
    StatusCode errorCode = initialize();
    if(errorCode != Success){
        errorCode = initializeFailureRecovery(errorCode);
    }
    while (errorCode == Success && !isFinished()) {
        //logger -> logWorldState();
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
    logger -> logError(errorCode);
    return errorCode;
}
