#ifndef TURNFORTIME
#define TURNFORTIME

#include "Command.h"
#include "Robot.h"

class TurnForTime :
    public Command
{
public:
    TurnForTime(Robot &robot_, int power_, int ms_);
    TurnForTime(Robot &robot_,  int power_, float sec);

    int changePower(int newPower);
    int changeDriveTime(int newTime);
    int changeDriveTime(float newTime);
private:
    Robot robot;
    int power;
    float timeToWait;
    float startTime;

    virtual int initialize();
    virtual int run();
    virtual bool isFinished();
    virtual int completion();

    int constructor(Robot &robot_, int power_, float sec_);
};

#endif
