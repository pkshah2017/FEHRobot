#ifndef DRIVETOBUTTONS
#define DRIVETOBUTTONS

#include "Task.h"
#include "Robot.h"
#include "Commands/DriveToPosition.h"

class DriveToButtons :
    public Task
{
public:
    DriveToButtons(Robot &robot_);
private:
    Robot robot;

    DriveToPosition leaveStart;
};

#endif
