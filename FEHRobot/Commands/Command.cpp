#include "Logger.h"
#include "Command.h"
#include <FEHUtility.h>
#include <FEHLCD.h>
#include <typeinfo>

Command::Command()
{
}

StatusCode Command::execute() {
    logger -> logMessage("\r\nBeginning Command: ");
    logger -> logMessage(getCommandName());
    logger -> logMessage("\r\n");
    StatusCode errorCode = initialize();
    if(errorCode != Success){
        logger->logMessage("Initialization Error");
        errorCode = initializeFailureRecovery(errorCode);
    }
    logger->logMessage("Command Initalized");
    while (errorCode == Success && !isFinished()) {
        logger -> logWorldState();
        StatusCode errorCode = run();
        if(errorCode != Success){
            //logger.printError(errorCode);
            errorCode = runFailureRecovery(errorCode);
        }
		Sleep(REFRESH_RATE);
	}
    logger->logMessage("Command Finished");
    logger -> logWorldState();
    errorCode = completion();
    logger -> logMessage("Completed Command: ");
    logger -> logMessage(getCommandName());
    logger -> logMessage("\r\n");
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
