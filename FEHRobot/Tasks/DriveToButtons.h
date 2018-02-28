#ifndef DRIVETOBUTTONS
#define DRIVETOBUTTONS

#include "Task.h"
#include "Robot.h"
#include "Commands/DriveForTime.h"
#include "Commands/CenterOnLine.h"

class DriveToButtons :
    public Task
{
public:
    DriveToButtons(Robot &robot_);
private:
    Robot robot;

    DriveForTime leaveStart;
    DriveForTime goToButtons;
    CenterOnLine centerOnLine;
};

#endif
