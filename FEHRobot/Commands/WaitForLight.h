#ifndef WAITFORLIGHT
#define WAITFORLIGHT

#include "Command.h"
#include "Robot.h"

class WaitForLight :
    public Command
{
public:
    WaitForLight(Robot &robot_);

    int setRobot(Robot &robot_);
private:
    Robot robot;

    virtual int initialize();
    virtual int run();
    virtual bool isFinished();
    virtual int completion();
};


#endif
