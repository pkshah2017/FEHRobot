#include "Commands/Command.h"
#include <stack>

class Task
{
private:
    std::stack<Command*> commandStack;

    virtual int commanFailureRecovery(int error);
public:
    Task();
	int execute();
    int addCommand(Command* command);

    //
    /*
    DriveForTime *d = DriveForTime(2342342,234234);
    addCommand(d);
    */

  //  DriveForTime d(2342342,234234);
  //  addCommand(&d);
    //
};

//TODO: Create a programSet which is chosen in program chooser
