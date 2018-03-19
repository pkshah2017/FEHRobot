#include "DriveToCrank.h"

DriveToCrank::DriveToCrank(Robot &robot_):
    waitForLight(robot_),
    driveForTime(robot_, 0, 50, 1350),
    driveToPosition(robot_, 0, 0),
    changeArmPosition(robot_, ArmUp, 500)
{
    robot = robot_;
}

StatusCode DriveToCrank::execute(){
    /*
     * Drive to wrench
     */
    //driveToPosition.setup(8.1f, 21.3f);
    //driveToPosition.execute();

    return Success;
}

