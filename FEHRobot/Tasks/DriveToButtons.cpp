#include "DriveToButtons.h"

DriveToButtons::DriveToButtons(Robot &robot_):
    waitForLight(robot_),
    driveForTime(robot_, 0, 50, 1350),
    centerOnLine(robot_)
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
    driveForTime.setup(0, 50, 1350);
    driveForTime.execute();

    /*
     * Drive to buttons
     */
    driveForTime.setup(90, 50, 1500);
    driveForTime.execute();

    /*
     * Center on the line
     */
    centerOnLine.execute();

    return Success;
}
