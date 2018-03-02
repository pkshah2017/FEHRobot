#include "DriveToButtons.h"

DriveToButtons::DriveToButtons(Robot &robot_):
    waitForLight(robot_),
    driveForTime(robot_, 0, 50, 1350),
    centerOnLine(robot_)
{
    robot = robot_;
}

int DriveToButtons::execute(){
    /*
     * Wait for start light
     */
    waitForLight.execute();

    /*
     * Drive out of start
     */
    driveForTime.execute();


    /*
     * Drive to buttons
     */
    driveForTime.changeHeading(90);
    driveForTime.changeDriveTime(1500);
    driveForTime.execute();

    /*
     * Center on the line
     */
    centerOnLine.execute();
}
