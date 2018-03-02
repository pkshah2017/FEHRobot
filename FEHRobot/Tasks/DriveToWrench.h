#ifndef DRIVETOWRENCH
#define DRIVETOWRENCH

#include "Task.h"
#include "Robot.h"
#include "Commands/DriveForTime.h"
#include "Commands/WaitForLight.h"
#include "Commands/CommandList.h"

class DriveToWrench :
    public Task
{
public:
    DriveToWrench(Robot &robot_);
private:
    Robot robot;

    WaitForLight waitForLight;
    DriveForTime driveForTime;
};

#endif
