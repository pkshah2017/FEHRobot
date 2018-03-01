#ifndef DRIVETOLINE
#define DRIVETOLINE

#include "Command.h"
#include "Robot.h"

class DriveToLine :
    public Command
{
public:
    DriveToLine(Robot &robot_, int power_);
private:
    Robot robot;
    int power;
    LineFollowerState lineFollowStatus;

    virtual int initialize();
    virtual int run();
    virtual bool isFinished();
    virtual int completion();

    int updateLineFollowerState(float leftThreshold, float centerThreshold, float rightTheshold);
};

#endif
