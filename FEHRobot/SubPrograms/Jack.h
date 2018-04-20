/*
 * This is the subprogram to handle to jack and drop off the wrench. 
*/
#ifndef JACK
#define JACK

#include "Subprogram.h"
#include "Robot.h"
#include "Tasks/DriveToJack.h"
#include "Tasks/LiftJack.h"
#include "Tasks/DriveToGarage.h"
#include "Tasks/DropOffWrench.h"

class Jack :
    public Subprogram
{
public:
    Jack(Robot *robot_);
private:
    Robot *robot;

    DriveToJack driveToJack;
    LiftJack liftJack;    
    DriveToGarage driveToGarage;
    DropOffWrench dropOffWrench;
};

#endif
