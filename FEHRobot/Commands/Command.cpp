#include "Command.h"
#include <FEHUtility.h>
#include <FEHLCD.h>

Command::Command()
{
}

int Command::execute() {
    StatusCode errorCode = initialize();
    if(errorCode != Success){
        errorCode = initializeFailureRecovery(errorCode);
    }
    while (errorCode == Success && !isFinished()) {
        StatusCode errorCode = run();
        if(errorCode != Success){
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
