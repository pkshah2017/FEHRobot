#ifndef JACK
#define JACK

#include "Subprogram.h"
#include "Robot.h"
#include "Tasks/DriveToJack.h"
#include "Tasks/LiftJack.h"

class Jack :
    public Subprogram
{
public:
    Jack(Robot *robot_);
private:
    Robot *robot;

    DriveToJack driveToJack;
    LiftJack liftJack;
};

#endif
