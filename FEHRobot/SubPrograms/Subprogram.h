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

    /*
    In subclasses do something like this
    DriveForTime *d = DriveForTime(2342342,234234);
    addCommand(d);
    */

    //  Do this
    //  DriveForTime d(2342342,234234);
    //  addCommand(&d);
};

#endif
