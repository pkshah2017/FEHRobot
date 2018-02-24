#include "Subprogram.h"

Subprogram::Subprogram()
{
}

int Subprogram::execute() {
    int errorCode = 0;
    while(!taskStack.empty() && errorCode == 0){
        Task* toRun = taskStack.top();
        taskStack.pop();
        errorCode = (*toRun).execute();
        if(errorCode != 0){
            errorCode = taskFailureRecovery(errorCode);
        }
    }
    return errorCode;
}

