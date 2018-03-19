#ifndef PRESSBUTTONS
#define PRESSBUTTONS

#include "Task.h"
#include "Robot.h"
#include "Commands/CommandList.h"

class PressButtons :
    public Task
{
public:
    PressButtons(Robot &robot_);

    virtual StatusCode execute();
private:
    Robot robot;

    ReadButtonLight readButtonLight;
    DriveForTime driveForTime;
    TurnForTime turnForTime;
    WaitForTime waitForTime;
    ChangeArmPosition changeArmPosition;
    DriveToPosition driveToPosition;
};

#endif
