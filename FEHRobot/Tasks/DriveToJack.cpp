#include "DriveToJack.h"

DriveToJack::DriveToJack(Robot &robot_):
    leaveBase(robot_, 0, 50, 1000),
    toFrontWall(robot_, 45, 50, RobotFront),
    toRightWall(robot_, 90, 50, RobotRight)
{
    robot = robot_;
    addCommand(&leaveBase);
    addCommand(&toFrontWall);
    addCommand(&toRightWall);
}

