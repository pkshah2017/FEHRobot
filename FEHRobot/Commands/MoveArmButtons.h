#ifndef MOVEARMBUTTONS
#define MOVEARMBUTTONS

#include "Command.h"
#include "Robot.h"
class MoveArmButtons :
    public Command
{
public:
    MoveArmButtons(Robot &robot_);
private:
    Robot robot;

    float timeToWait;
    float startTime;

    int LightStatus;

    virtual int initialize();
    virtual int run();
    virtual bool isFinished();
    virtual int completion();
};


#endif
