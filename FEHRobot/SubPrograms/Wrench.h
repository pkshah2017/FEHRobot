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
    Jack(Robot &robot_);
private:
    Robot robot;

    DriveToWrench driveToWrench;
    PickUpWrench pickUpWrench;
};

#endif
