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
};
