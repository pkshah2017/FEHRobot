#include "DriveToWrench.h"

DriveToWrench::DriveToWrench(Robot &robot_):
    waitForLight(robot_),
    driveForTime(robot_, 0, 50, 1350),
    driveToPosition(robot_, 0, 0),
    changeArmPosition(robot_, ArmUp, 500)
{
    robot = robot_;
}

int DriveToWrench::execute(){
    /*
     * Wait for start light
     */
    waitForLight.execute();

    /*
     * Raise Arm
     */
    changeArmPosition.selectArmPosition(ArmUp);
    changeArmPosition.selectWaitTime(500);
    changeArmPosition.execute();

    /*
     * Drive out of start
     */
    driveToPosition.changeXSetpoint(17.2);
    driveToPosition.changeYSetpoint(21.3);
    driveToPosition.execute();

    /*
     * Drive to wrench
     */
    driveToPosition.changeXSetpoint(8.1);
    driveToPosition.changeYSetpoint(21.3);
    driveToPosition.execute();
}

