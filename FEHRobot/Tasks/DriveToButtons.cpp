#include "DriveToButtons.h"

DriveToButtons::DriveToButtons(Robot &robot_):
    leaveStart(robot_, 18, 21),
    centerOnLine(robot_)
{
    robot = robot_;
    addCommand(&centerOnLine);
}

