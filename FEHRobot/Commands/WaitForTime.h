#ifndef WAITFORTIME
#define WAITFORTIME

#include "Command.h"
#include "Robot.h"

class WaitForTime :
    public Command
{
public:
    WaitForTime(Robot *robot_, int ms_);
    WaitForTime(Robot *robot_, float sec);

    StatusCode changeDriveTime(int newTime);
    StatusCode changeDriveTime(float newTime);
private:
    Robot *robot;
    float timeToWait;
    float startTime;

    virtual StatusCode initialize();
    virtual StatusCode run();
    virtual bool isFinished();
    virtual StatusCode completion();

    StatusCode constructor(Robot *robot_, float sec_);
};

#endif
