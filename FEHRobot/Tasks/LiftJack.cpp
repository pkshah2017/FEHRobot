#include "LiftJack.h"

LiftJack::LiftJack(Robot *robot_):
    driveForTime(robot_, 90, 50, 700)
{
    robot = robot_;
}

StatusCode LiftJack::execute(){
    driveForTime.setup(90, 90, 500);
    StatusCode status = driveForTime.execute();

    return status;
}

