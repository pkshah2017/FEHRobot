#include "DriveToJack.h"

DriveToJack::DriveToJack(Robot &robot_):
    runIntoJack(robot_, 270, 50, 2500)
{
    robot = robot_;
    addCommand(&runIntoJack);
}

