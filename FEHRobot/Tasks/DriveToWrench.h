#ifndef DRIVETOWRENCH
#define DRIVETOWRENCH

#include "Task.h"
#include "Robot.h"
#include "Commands/CommandList.h"

class DriveToWrench :
    public Task
{
public:
    DriveToWrench(Robot &robot_);

    virtual int execute();
private:
    Robot robot;

    WaitForLight waitForLight;
    DriveForTime driveForTime;
    DriveToPosition driveToPosition;
    ChangeArmPosition changeArmPosition;
};

#endif
