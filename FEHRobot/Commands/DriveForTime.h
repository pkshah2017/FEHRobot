#ifndef DRIVEFORTIME
#define DRIVEFORTIME

#include "Command.h"
#include "Robot.h"

class DriveForTime :
    public Command
{
public:
    DriveForTime(Robot &robot_,  int heading_, int power_, float sec_);
    DriveForTime(Robot &robot_,  int heading_, int power_, int ms);

    void setup(int newHeading,int newPower, int newTime);
    void setup(int newHeading,int newPower, float newTime);

    int changeHeading(int newHeading);
    int changePower(int newPower);
    int changeDriveTime(int newTime);
    int changeDriveTime(float newTime);
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
