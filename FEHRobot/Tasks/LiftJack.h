#ifndef LIFTJACK
#define LIFTJACK

#include "Task.h"
#include "Robot.h"
#include "Commands/DriveForTime.h"

class DriveToJack :
    public Task
{
public:
    DriveToJack(Robot &robot_);
private:
    Robot robot;

    DriveForTime runIntoJack;
};

#endif
