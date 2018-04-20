/*
 * This is the subprogram to handle to wrench. It moves the robot from the buttons to the wrench and picks up the wrench.
*/
#ifndef WRENCH
#define WRENCH

#include "Subprogram.h"
#include "Robot.h"
#include "Tasks/DriveToWrench.h"
#include "Tasks/PickUpWrench.h"


class Wrench :
    public Subprogram
{
public:
    Wrench(Robot *robot_);
private:
    Robot *robot;

    DriveToWrench driveToWrench;
    PickUpWrench pickUpWrench;

};

#endif
