#ifndef PICKUPWRENCH
#define PICKUPWRENCH

#include "Task.h"
#include "Robot.h"
#include "Commands/CommandList.h"

class PickUpWrench :
    public Task
{
public:
    PickUpWrench(Robot *robot_);

    virtual StatusCode execute();
private:
    Robot *robot;

    DriveForTime driveForTime;
    TurnForTime turnForTime;
    WaitForTime waitForTime;
    ChangeArmPosition changeArmPosition;
    DriveTilBump driveTilBump;
    DriveToLine driveToLine;
};

#endif
