#ifndef DRIVETOEND
#define DRIVETOEND

#include "Task.h"
#include "Robot.h"
#include "Commands/CommandList.h"

class DriveToEnd :
    public Task
{
public:
    DriveToEnd(Robot &robot_);

    virtual StatusCode execute();
private:
    Robot robot;

    WaitForLight waitForLight;
    DriveForTime driveForTime;
    DriveToPosition driveToPosition;
    ChangeArmPosition changeArmPosition;
};

#endif
