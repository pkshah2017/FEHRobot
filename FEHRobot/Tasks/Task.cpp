#include "Task.h"

Task::Task()
{
}

int Task::execute() {
    int errorCode = 0;
    while(!commandQueue.empty() && errorCode == 0){
        Command* toRun = commandQueue.front();
        commandQueue.pop();
        errorCode = (*toRun).execute();
        if(errorCode != 0){
            errorCode = commanFailureRecovery(errorCode);
        }
    }
    return errorCode;
}

int Task::addCommand(Command* command){
    commandQueue.push(command);

    return 0;
}
