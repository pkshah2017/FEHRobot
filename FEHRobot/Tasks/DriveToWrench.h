#ifndef DRIVETOWRENCH
#define DRIVETOWRENCH

#include "Task.h"
#include "Robot.h"
#include "Commands/DriveForTime.h"
#include "Commands/WaitForLight.h"

class DriveToWrench :
    public Task
{
public:
    DriveToWrench(Robot &robot_);
private:
    Robot robot;

    WaitForLight waitToStart;
    DriveForTime leaveStart;
    DriveForTime goToWrench;
};

#endif
