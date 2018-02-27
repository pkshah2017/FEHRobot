#include "Task.h"

Task::Task()
{
    addIndex = 0;
    runIndex = 0;
}

int Task::execute() {
    int errorCode = 0;
    /*
    while(!commandQueue.empty() && errorCode == 0){
        Command* toRun = commandQueue.front();
        commandQueue.pop();
        errorCode = (*toRun).execute();
        if(errorCode != 0){
            errorCode = commanFailureRecovery(errorCode);
        }
    }
    */
    while(runIndex < addIndex && errorCode == 0){
        Command* toRun = commandArray[runIndex];
        errorCode = (*toRun).execute();
        if(errorCode != 0){
            errorCode = commandFailureRecovery(errorCode);
        }
        runIndex++;
    }
    return errorCode;
}

int Task::addCommand(Command* command){
    commandArray[addIndex] = command;
    addIndex++;
    return 0;
}

int Task::commandFailureRecovery(int error){
    return error;
}
