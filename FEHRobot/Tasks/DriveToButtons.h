#ifndef DRIVETOBUTTONS
#define DRIVETOBUTTONS

#include "Task.h"
#include "Robot.h"
#include "Commands/CommandList.h"

class DriveToButtons :
    public Task
{
public:
    DriveToButtons(Robot *robot_);

    virtual StatusCode execute();
private:
    Robot *robot;

    WaitForLight waitForLight;
    DriveForTime driveForTime;
    CenterOnLine centerOnLine;
    TurnForTime turnForTime;
    ChangeArmPosition changeArmPosition;
    DriveToPosition driveToPosition;
};

#endif
