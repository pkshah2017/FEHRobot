#include "DriveToWrench.h"

DriveToWrench::DriveToWrench(Robot &robot_):
    waitToStart(robot_),
    leaveStart(robot_, 0, 50, 1350),
    goToWrench(robot_, 270, 50, 1500)
{
    robot = robot_;
    addCommand(&waitToStart);
    addCommand(&leaveStart);
    addCommand(&goToWrench);
}

