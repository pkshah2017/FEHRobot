#ifndef PRESSBUTTONS
#define PRESSBUTTONS

#include "Task.h"
#include "Robot.h"
#include "Commands/MoveArmButtons.h"
#include "Commands/DriveForTime.h"
#include "Commands/WaitForTime.h"
#include "Commands/TurnForTime.h"

class PressButtons :
    public Task
{
public:
    PressButtons(Robot &robot_);
private:
    Robot robot;

    MoveArmButtons moveArmButtons;
    DriveForTime moveToButtons;
    DriveForTime touchButtons;
    WaitForTime holdButtons;
    TurnForTime turnIntoButtons;
    DriveForTime backAwayFromButtons;
    DriveForTime moveToWrench;
    DriveForTime moveTowardStart;
    DriveForTime pressFinalButton;

};

#endif
