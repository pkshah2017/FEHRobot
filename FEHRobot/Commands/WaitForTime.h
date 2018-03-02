#ifndef WAITFORTIME
#define WAITFORTIME

#include "Command.h"
#include "Robot.h"

class WaitForTime :
    public Command
{
public:
    WaitForTime(Robot &robot_, int ms_);
    WaitForTime(Robot &robot_, float sec);
private:
    Robot robot;
    float timeToWait;
    float startTime;

    virtual int initialize();
    virtual int run();
    virtual bool isFinished();
    virtual int completion();

    int constructor(Robot &robot_, float sec_);
};

#endif
