#ifndef PRESSBUTTONS
#define PRESSBUTTONS

#include "Task.h"
#include "Robot.h"
#include "Commands/MoveArmButtons.h"
#include "Commands/DriveForTime.h"
#include "Commands/WaitForTime.h"
#include "Commands/TurnForTime.h"
#include "Commands/ChangeArmPosition.h"

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
    TurnForTime turnIntoButtons;
    WaitForTime holdButtons;
    DriveForTime backAwayFromButtons;
    ChangeArmPosition raiseArm;
    DriveForTime moveToWrench;
    ChangeArmPosition lowerArm;
    ChangeArmPosition liftWrench;
    DriveForTime moveTowardStart;
    DriveForTime pressFinalButton;

    virtual int commandFailureRecovery(int error);

};

#endif
