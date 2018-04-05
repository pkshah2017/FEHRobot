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
        errorCode = run();
        if(errorCode != Success){
            //logger.printError(errorCode);
            errorCode = runFailureRecovery(errorCode);
        }
		Sleep(REFRESH_RATE);
	}
    logger->logMessage("Command Finished");
    logger -> logWorldState();
    if(errorCode == Success){
        errorCode = completion();
    } else {
        errorCode = completionFailureRecovery(errorCode);
    }
    logger -> logMessage("Completed Command: ");
    logger -> logMessage(getCommandName());
    logger -> logMessage("\r\n");
    logger->logMessage("Status code at the end of command is");
    logger->logError(errorCode);
    return errorCode;
}

StatusCode Command::initializeFailureRecovery(StatusCode errorCode){
    logger->logMessage("Initalize Failed");
    return printError(errorCode);
}

StatusCode Command::runFailureRecovery(StatusCode errorCode){
    logger->logMessage("Run method Failed");
    return printError(errorCode);
}

StatusCode Command::completionFailureRecovery(StatusCode errorCode){
    logger->logMessage("Code prior to Completion Failed");
    completion();
    return printError(errorCode);
}

StatusCode Command::printError(StatusCode errorCode){
    logger -> logError(errorCode);
    return errorCode;
}
