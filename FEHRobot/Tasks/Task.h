#ifndef TASK
#define TASK

#include "Commands/Command.h"

class Task
{
private:
    Command* commandArray[MAX_COMMANDS];
    int addIndex;
    int runIndex;

    virtual int commandFailureRecovery(int error);
public:
    Task();
	int execute();
    int addCommand(Command* command);
};

#endif
