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
    TurnForTime turnForTime;
    TurnToHeadingZero turnToHeadingZero;
    BackupToLineSingleOpto backupToLineSingleOpto;
    BackupOffLineSingleOpto backupOffLineSingleOpto;

    void alignWithWrench();
};

#endif
