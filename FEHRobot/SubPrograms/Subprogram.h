#ifndef SUBPROGRAM
#define SUBPROGRAM

#include "Tasks/Task.h"
#include <queue>

class Subprogram
{
private:
    std::queue<Task*> taskQueue;

    virtual int taskFailureRecovery(int error);
public:
    Subprogram();
    int execute();
    int addTask(Task* task);
};

#endif
