#ifndef WRENCH
#define WRENCH

#include "Subprogram.h"
#include "Robot.h"
#include "Tasks/DriveToWrench.h"
#include "Tasks/PickUpWrench.h"
#include "Tasks/DriveToGarage.h"
#include "Tasks/DropOffWrench.h"


class Wrench :
    public Subprogram
{
public:
    Wrench(Robot &robot_);
private:
    Robot robot;

    DriveToWrench driveToWrench;
    PickUpWrench pickUpWrench;
    DriveToGarage driveToGarage;
    DropOffWrench dropOffWrench;

};

#endif
