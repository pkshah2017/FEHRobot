#ifndef LINEFOLLOWFORTIME
#define LINEFOLLOWFORTIME

#include "Command.h"
#include "Robot.h"

class LineFollowForTime :
    public Command
{
public:
    LineFollowForTime(Robot &robot_, int power_, int ms_);
    LineFollowForTime(Robot &robot_, int power_, float sec);
private:
    Robot robot;
    int power;
    LineFollowerState lineFollowStatus;
    float timeToWait;
    float startTime;

    virtual int initialize();
    virtual int run();
    virtual bool isFinished();
    virtual int completion();

    int constructor(Robot &robot_, int power_, float sec_);
    int updateLineFollowerState(float leftThreshold, float centerThreshold, float rightTheshold);
};

#endif
