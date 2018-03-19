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

    StatusCode setup(int newHeading,int newPower, int newTime);
    StatusCode setup(int newHeading,int newPower, float newTime);

    StatusCode changeHeading(int newHeading);
    StatusCode changePower(int newPower);
    StatusCode changeDriveTime(int newTime);
    StatusCode changeDriveTime(float newTime);
private:
    Robot robot;
    int heading;
    int power;
    float timeToWait;
    float startTime;

    virtual StatusCode initialize();
    virtual StatusCode run();
    virtual bool isFinished();
    virtual StatusCode completion();

    StatusCode constructor(Robot &robot_, int heading_, int power_, float sec_);
};

#endif
