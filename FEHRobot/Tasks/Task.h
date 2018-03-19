#ifndef TASK
#define TASK

#include "Commands/Command.h"
#include <FEHLCD.h>

class Task
{
private:
    virtual StatusCode checkStatus(StatusCode status);
public:
    Task();
    virtual StatusCode execute() = 0;
};

#endif
