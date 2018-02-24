#ifndef DRIVETOJACK
#define DRIVETOJACK

#include "Task.h"
#include "Robot.h"
#include "Commands/DriveTilBump.h"
#include "Commands/DriveForTime.h"

class DriveToJack :
    public Task
{
public:
    DriveToJack(Robot &robot_);
private:
    Robot robot;

    DriveForTime leaveBase;
    DriveTilBump toFrontWall;
    DriveTilBump toRightWall;
};

#endif
