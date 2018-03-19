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

    StatusCode setup(int newPower, int newTimeMS);
    StatusCode setup(int newPower, float newTimeSec);

    StatusCode changePower(int newPower);
    StatusCode changeDriveTime(int newTime);
    StatusCode changeDriveTime(float newTime);
private:
    Robot robot;
    int power;
    float timeToWait;
    float startTime;

    virtual StatusCode initialize();
    virtual StatusCode run();
    virtual bool isFinished();
    virtual StatusCode completion();

    StatusCode constructor(Robot &robot_, int power_, float sec_);
};

#endif
