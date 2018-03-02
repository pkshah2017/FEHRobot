#include "DriveToWrench.h"

DriveToWrench::DriveToWrench(Robot &robot_):
    waitForLight(robot_),
    driveForTime(robot_, 0, 50, 1350)
{
    robot = robot_;
}

int DriveToWrench::execute(){
    /*
     * Wait for start light
     */
    waitForLight.execute();

    /*
     * Drive out of start
     */
    driveForTime.execute();

    /*
     * Drive to wrench
     */
    driveForTime.changeHeading(270);
    driveForTime.changeDriveTime(1500);
    driveForTime.execute();
}

