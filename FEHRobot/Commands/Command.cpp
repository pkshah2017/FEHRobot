#include "Command.h"
#include <FEHUtility.h>
#include <FEHLCD.h>

Command::Command()
{
}

int Command::execute() {
    int errorCode = initialize();
    if(errorCode != SUCCESS){
        errorCode = initializeFailureRecovery(errorCode);
    }
    while (errorCode == SUCCESS && !isFinished()) {
        int errorCode = run();
        if(errorCode != SUCCESS){
            errorCode = runFailureRecovery(errorCode);
        }
		Sleep(REFRESH_RATE);
	}
    errorCode = completion();
    return errorCode;
}

int Command::initializeFailureRecovery(int errorCode){
    LCD.Write("ERROR: ");
    LCD.WriteLine(errorCode);
    return errorCode;
}

int Command::runFailureRecovery(int errorCode){
    LCD.Write("ERROR: ");
    LCD.WriteLine(errorCode);
    return errorCode;
}
