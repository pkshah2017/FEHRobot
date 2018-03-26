#include "DriveToButtons.h"

DriveToButtons::DriveToButtons(Robot *robot_):
    waitForLight(robot_),
    driveForTime(robot_, 0, 50, 1350),
    centerOnLine(robot_),
    driveToPosition(robot_, 0.0f, 0.0f)
{
    robot = robot_;
}

StatusCode DriveToButtons::execute(){
    /*
     * Wait for start light
     */
    waitForLight.execute();

    /*
     * Drive out of start
     */
    driveForTime.setup(0, 50, 300);
    driveForTime.execute();

    /*
     * Drive to buttons
     */
    driveToPosition.setup(24.8f, 20.7f, 50);
    driveToPosition.execute();

    /*
     * Center on the line
     */
    centerOnLine.execute();

    return Success;
}
