#include "Command.h"
#include <FEHUtility.h>

Command::Command()
{
}

int Command::execute() {
    int errorCode = initialize();
    if(errorCode != 0){
        errorCode = initializeFailureRecovery(errorCode);
    }
    while (errorCode == 0 && !isFinished()) {
        int errorCode = run();
        if(errorCode != 0){
            errorCode = runFailureRecovery(errorCode);
        }
		Sleep(REFRESH_RATE);
	}
    return errorCode;
}

int Command::initializeFailureRecovery(int errorCode){
    return errorCode;
}

int Command::runFailureRecovery(int errorCode){
    return errorCode;
}
