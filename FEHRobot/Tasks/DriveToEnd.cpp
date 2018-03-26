#include "DriveToEnd.h"

DriveToEnd::DriveToEnd(Robot *robot_):
    waitForLight(robot_),
    driveForTime(robot_, 0, 50, 1350),
    driveToPosition(robot_, 0, 0),
    changeArmPosition(robot_, ArmUp, 500),
    changeCrankArmPosition(robot_, ArmUp, 500),
    turnForTime(robot_, 0, 0)
{
    robot = robot_;
}

StatusCode DriveToEnd::execute(){

    /*
     * Move To Center of Top Level
     */
    driveToPosition.setup(17.3f, 58.8f, 80);
    driveToPosition.execute();

    changeArmPosition.selectArmPosition(ArmUp);
    changeArmPosition.execute();
    changeCrankArmPosition.selectArmPosition(ArmUp);
    changeCrankArmPosition.execute();
    /*
     * Rotate Clockwise
     */
    turnForTime.setup(-50, .4f);
    turnForTime.execute();

    /*
     * Go Towards the top of the ramp
     */
    driveToPosition.setup(31.8f, 41.9f, 80);
    driveToPosition.execute();

    /*
     * Move down Ramp
     */
    driveToPosition.setup(31.8f, 29.0f, 80);
    driveToPosition.execute();

    /*
     * Move to outside start
     */
    driveToPosition.setup(21.0f, 21.5f, 80);
    driveToPosition.execute();

    /*
     * Move to start
     */
    driveToPosition.setup(17.7f, 30.0f, 80);
    driveToPosition.execute();

    return Success;
}

