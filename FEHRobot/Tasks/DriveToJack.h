#ifndef DRIVETOJACK
#define DRIVETOJACK

#include "Task.h"
#include "Robot.h"
#include "Commands/CommandList.h"

class DriveToJack :
    public Task
{
public:
    DriveToJack(Robot *robot_);

    virtual StatusCode execute();
private:
    Robot *robot;

    DriveForTime driveForTime;
    DriveToPosition driveToPosition;
    DriveTilBump driveTilBump;
    TurnForTime turnForTime;
};

#endif
