#ifndef TASK
#define TASK

#include "Commands/Command.h"

class Task
{
private:
    virtual int checkStatus(int status);
public:
    Task();
    virtual int execute() = 0;
};

#endif
