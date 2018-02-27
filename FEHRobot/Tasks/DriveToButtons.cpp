#include "DriveToButtons.h"

DriveToButtons::DriveToButtons(Robot &robot_):
    leaveStart(robot_, 18, 21)
{
    robot = robot_;
    addCommand(&leaveStart);
}

