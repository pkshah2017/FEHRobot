#include "LiftJack.h"

LiftJack::LiftJack(Robot *robot_):
    driveForTime(robot_, 90, 50, 2500)
{
    robot = robot_;
}

StatusCode LiftJack::execute(){
    driveForTime.setup(90, 80, 1300);
    StatusCode status = driveForTime.execute();

    return status;
}

