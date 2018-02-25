#ifndef TASK
#define TASK

#include "Commands/Command.h"
#include <queue>

class Task
{
private:
    std::queue<Command*> commandQueue;

    virtual int commanFailureRecovery(int error);
public:
    Task();
	int execute();
    int addCommand(Command* command);
};

#endif
