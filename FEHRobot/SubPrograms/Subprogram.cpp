#include "Subprogram.h"

Subprogram::Subprogram()
{
}

int Subprogram::execute() {
    int errorCode = 0;
    while(!taskQueue.empty() && errorCode == 0){
        Task* toRun = taskQueue.front();
        taskQueue.pop();
        errorCode = (*toRun).execute();
        if(errorCode != 0){
            errorCode = taskFailureRecovery(errorCode);
        }
    }
    return errorCode;
}

int Subprogram::addTask(Task* task){
    taskQueue.push(task);

    return 0;
}
