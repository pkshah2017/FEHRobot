#include "Subprogram.h"
#include <FEHUtility.h>

Subprogram::Subprogram()
{
    addIndex = 0;
    runIndex = 0;
}

int Subprogram::execute() {
    int errorCode = 0;
    /*
    while(!taskQueue.empty() && errorCode == 0){
        Task* toRun = taskQueue.front();
        taskQueue.pop();
        errorCode = (*toRun).execute();
        if(errorCode != 0){
            errorCode = taskFailureRecovery(errorCode);
        }
    }
    */
    while(runIndex < addIndex && errorCode == 0){
        Task* toRun = taskArray[runIndex];
        errorCode = (*toRun).execute();
        if(errorCode != 0){
            errorCode = taskFailureRecovery(errorCode);
        }
        runIndex++;
    }
    return errorCode;
}

int Subprogram::addTask(Task* task){
    taskArray[addIndex] = task;
    addIndex++;
    return 0;
}

int Subprogram::taskFailureRecovery(int error){
    return error;
}
