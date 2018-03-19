#ifndef DROPOFFWRENCH
#define DROPOFFWRENCH

#include "Task.h"
#include "Robot.h"
#include "Commands/CommandList.h"

class DropOffWrench :
    public Task
{
public:
    DropOffWrench(Robot &robot_);

    virtual StatusCode execute();
private:
    Robot robot;

    DriveForTime driveForTime;
    TurnForTime turnForTime;
    WaitForTime waitForTime;
    ChangeArmPosition changeArmPosition;
    DriveTilBump driveTilBump;
    DriveToLine driveToLine;
};

#endif
