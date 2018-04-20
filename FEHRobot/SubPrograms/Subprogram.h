/*
 * This is the subprogram abstract class. It allows for the easy adding of tasks to run through them in order.
*/
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
