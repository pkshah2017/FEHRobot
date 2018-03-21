#ifndef DRIVETOGARAGE
#define DRIVETOGARAGE

#include "Task.h"
#include "Robot.h"
#include "Commands/CommandList.h"

class DriveToGarage :
    public Task
{
public:
    DriveToGarage(Robot *robot_);

    virtual StatusCode execute();
private:
    Robot *robot;

    WaitForLight waitForLight;
    DriveForTime driveForTime;
    DriveTilBump driveTilBump;
    DriveToPosition driveToPosition;
    ChangeArmPosition changeArmPosition;
    TurnForTime turnForTime;
    DriveToLine driveToLine;
};

#endif
