#ifndef CRANK
#define CRANK

#include "Subprogram.h"
#include "Robot.h"
#include "Tasks/DriveToCrank.h"
#include "Tasks/TurnCrank.h"
#include "Tasks/DriveToEnd.h"


class Crank :
    public Subprogram
{
public:
    Crank(Robot *robot_);
private:
    Robot *robot;

    DriveToCrank driveToCrank;
    TurnCrank turnCrank;
    DriveToEnd driveToEnd;

};

#endif
