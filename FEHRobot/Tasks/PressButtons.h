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

    virtual int execute();
private:
    Robot robot;
    ButtonColor buttonColor;

    MoveArmButtons moveArmButtons;
    DriveForTime driveForTime;
    TurnForTime turnForTime;
    WaitForTime waitForTime;
    ChangeArmPosition changeArmPosition;
};

#endif
