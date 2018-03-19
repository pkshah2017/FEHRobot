#ifndef DRIVETOLINE
#define DRIVETOLINE

#include "Command.h"
#include "Robot.h"

class DriveToLine :
    public Command
{
public:
    DriveToLine(Robot &robot_, int power_);

    StatusCode changePower(int newPower);
private:
    Robot robot;
    int power;
    LineFollowerState lineFollowStatus;

    virtual StatusCode initialize();
    virtual StatusCode run();
    virtual bool isFinished();
    virtual StatusCode completion();

    StatusCode updateLineFollowerState(float leftThreshold, float centerThreshold, float rightTheshold);
};

#endif
