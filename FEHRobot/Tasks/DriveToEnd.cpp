#include "DriveToEnd.h"

DriveToEnd::DriveToEnd(Robot &robot_):
    waitForLight(robot_),
    driveForTime(robot_, 0, 50, 1350),
    driveToPosition(robot_, 0, 0),
    changeArmPosition(robot_, ArmUp, 500)
{
    robot = robot_;
}

StatusCode DriveToEnd::execute(){

    return Success;
}

