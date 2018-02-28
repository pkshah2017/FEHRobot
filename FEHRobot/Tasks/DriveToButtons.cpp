#include "DriveToButtons.h"

DriveToButtons::DriveToButtons(Robot &robot_):
    waitToStart(robot_),
    leaveStart(robot_, 0, 50, 1350),
    goToButtons(robot_, 90, 50, 1500),
    centerOnLine(robot_)
{
    robot = robot_;
    addCommand(&waitToStart);
    addCommand(&leaveStart);
    addCommand(&goToButtons);
    addCommand(&centerOnLine);
}

