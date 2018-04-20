/*
 * This command makes the robot wait for a certain amount of time. 
*/
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

    virtual const char* getCommandName();
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
