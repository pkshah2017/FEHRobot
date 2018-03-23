#ifndef LINEFOLLOWFORTIME
#define LINEFOLLOWFORTIME

#include "Command.h"
#include "Robot.h"

class LineFollowForTime :
    public Command
{
public:
    LineFollowForTime(Robot *robot_, int power_, int ms_);
    LineFollowForTime(Robot *robot_, int power_, float sec);

    StatusCode setup(int newPower, int newTimeMS);
    StatusCode setup(int newPower, float newTimeSec);

    StatusCode changePower(int newPower);
    StatusCode changeDriveTime(int newTime);
    StatusCode changeDriveTime(float newTime);

    virtual const char* getCommandName();
private:
    Robot *robot;
    int power;
    LineFollowerState lineFollowStatus;
    float timeToWait;
    float startTime;

    virtual StatusCode initialize();
    virtual StatusCode run();
    virtual bool isFinished();
    virtual StatusCode completion();

    StatusCode constructor(Robot *robot_, int power_, float sec_);
    StatusCode updateLineFollowerState(float leftThreshold, float centerThreshold, float rightTheshold);
};

#endif
