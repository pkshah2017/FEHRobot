#ifndef LIFTJACK
#define LIFTJACK

#include "Task.h"
#include "Robot.h"
#include "Commands/DriveForTime.h"

class LiftJack :
    public Task
{
public:
    LiftJack(Robot &robot_);

    virtual int execute();
private:
    Robot robot;

    DriveForTime driveForTime;
};

#endif
