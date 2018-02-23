#include "Commands/Command.h"
#include <stack>

class Task
{
private:
    std::stack<Task*> taskStack;

    virtual int taskFailureRecovery(int error);
public:
    Task();
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
