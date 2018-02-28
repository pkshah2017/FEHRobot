#ifndef DRIVEFORTIME
#define DRIVEFORTIME

#include "Command.h"
#include "Robot.h"

class DriveForTime :
    public Command
{
public:
    DriveForTime(Robot &robot_, int heading_, int power_, int ms_);
    DriveForTime(Robot &robot_, int heading_, int power_, float sec);

    int changeHeading(int newHeading);
private:
    Robot robot;
    int heading;
    int power;
    float timeToWait;
    float startTime;

    virtual int initialize();
    virtual int run();
    virtual bool isFinished();
    virtual int completion();

    int constructor(Robot &robot_, int heading_, int power_, float sec_);
};

#endif
