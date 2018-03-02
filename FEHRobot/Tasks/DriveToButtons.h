#ifndef DRIVETOBUTTONS
#define DRIVETOBUTTONS

#include "Task.h"
#include "Robot.h"
#include "Commands/CommandList.h"

class DriveToButtons :
    public Task
{
public:
    DriveToButtons(Robot &robot_);

    virtual int execute();
private:
    Robot robot;

    WaitForLight waitForLight;
    DriveForTime driveForTime;
    CenterOnLine centerOnLine;
};

#endif
