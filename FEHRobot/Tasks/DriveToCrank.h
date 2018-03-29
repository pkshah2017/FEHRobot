#ifndef DRIVETOCRANK
#define DRIVETOCRANK

#include "Task.h"
#include "Robot.h"
#include "Commands/CommandList.h"

class DriveToCrank :
    public Task
{
public:
    DriveToCrank(Robot *robot_);

    virtual StatusCode execute();
private:
    Robot *robot;

    DriveForTime driveForTime;
    DriveToPosition driveToPosition;    
    TurnForTime turnForTime;
    DriveToPositionWithHeading driveToPositionWithHeading;
    ChangeCrankArmPosition changeCrankArmPosition;
};

#endif
