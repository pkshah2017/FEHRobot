#include "Task.h"

Task::Task()
{
}

int Task::execute() {
    int errorCode = 0;
    while(!commandStack.empty() && errorCode == 0){
        Command* toRun = commandStack.pop();
        errorCode = (*toRun).execute();
        if(errorCode != 0){
            errorCode = commanFailureRecovery(errorCode);
        }
    }
    return errorCode;
}

int Task::addCommand(Command* command){
    commandStack.push(command);

    return 0;
}
