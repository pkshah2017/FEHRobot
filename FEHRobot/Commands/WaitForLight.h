#ifndef WAITFORLIGHT
#define WAITFORLIGHT

#include "Command.h"
#include "Robot.h"

class WaitForLight :
    public Command
{
public:
    WaitForLight(Robot &robot_);
private:
    Robot robot;

    virtual StatusCode initialize();
    virtual StatusCode run();
    virtual bool isFinished();
    virtual StatusCode completion();
};


#endif
