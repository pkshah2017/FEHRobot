#ifndef SUBPROGRAM
#define SUBPROGRAM

#include "Tasks/Task.h"

class Subprogram
{
private:
    Task* taskArray[MAX_TASKS];
    int addIndex;
    int runIndex;

    virtual int taskFailureRecovery(int error);
public:
    Subprogram();
    int execute();
    int addTask(Task* task);
};

#endif
