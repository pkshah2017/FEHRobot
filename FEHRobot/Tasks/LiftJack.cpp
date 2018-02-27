#include "LiftJack.h"

LiftJack::LiftJack(Robot &robot_):
    runIntoJack(robot_, 90, 50, 2500)
{
    robot = robot_;
    addCommand(&runIntoJack);
}

