#include "LiftJack.h"

LiftJack::LiftJack(Robot &robot_):
    driveForTime(robot_, 90, 50, 2500)
{
    robot = robot_;
}

int LiftJack::execute(){
    int status = driveForTime.execute();

    return status;
}

