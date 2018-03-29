#ifndef DRIVETOWRENCH
#define DRIVETOWRENCH

#include "Task.h"
#include "Robot.h"
#include "Commands/CommandList.h"

class DriveToWrench :
    public Task
{
public:
    DriveToWrench(Robot *robot_);

    virtual StatusCode execute();
private:
    Robot *robot;

    WaitForLight waitForLight;
    DriveForTime driveForTime;
    DriveToPosition driveToPosition;
    DriveTilBump driveTilBump;
    DriveToPositionWithHeading driveToPositionWithHeading;
    ChangeArmPosition changeArmPosition;
    BackupToLine backupToLine;
};

#endif
