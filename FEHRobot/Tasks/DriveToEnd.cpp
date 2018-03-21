#include "DriveToEnd.h"

DriveToEnd::DriveToEnd(Robot *robot_):
    waitForLight(robot_),
    driveForTime(robot_, 0, 50, 1350),
    driveToPosition(robot_, 0, 0),
    changeArmPosition(robot_, ArmUp, 500)
{
    robot = robot_;
}

StatusCode DriveToEnd::execute(){

    /*
     * Move To Center of Top Level
     */
    driveToPosition.setup(17.3f, 58.8f);
    driveToPosition.execute();

    /*
     * Go Towards the top of the ramp
     */
    driveToPosition.setup(31.8f, 41.9f);
    driveToPosition.execute();

    /*
     * Move down Ramp
     */
    driveToPosition.setup(31.8f, 21.9f);
    driveToPosition.execute();

    /*
     * Move to outside start
     */
    driveToPosition.setup(17.0f, 21.5f);
    driveToPosition.execute();

    /*
     * Move to start
     */
    driveToPosition.setup(17.7f, 30.0f);
    driveToPosition.execute();

    return Success;
}

