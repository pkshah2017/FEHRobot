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
private:
    Robot robot;

    DriveForTime runIntoJack;
};

#endif
