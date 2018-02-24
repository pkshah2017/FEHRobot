#ifndef SUBPROGRAM
#define SUBPROGRAM

#include "Tasks/Task.h"
#include <stack>

class Subprogram
{
private:
    std::stack<Task*> taskStack;

    virtual int taskFailureRecovery(int error);
public:
    Subprogram();
    int execute();
    int addTask(Task* task);
};

#endif
