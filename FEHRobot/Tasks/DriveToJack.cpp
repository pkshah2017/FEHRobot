#include "DriveToJack.h"

DriveToJack::DriveToJack(Robot &robot_):
    driveForTime(robot_, 0, 50, 1000),
    driveTilBump(robot_, 315, 50, RobotFront)
{
    robot = robot_;
}

int DriveToJack::execute(){


    /*
     * Drive towards wrench/start/jack
     */
    driveForTime.changeDriveTime(1500);
    driveForTime.changeHeading(270);
    driveForTime.changePower(50);
    driveForTime.execute();

    /*
     * Drive to Wall
     */
    driveForTime.changeDriveTime(3500);
    driveForTime.changeHeading(315);
    driveForTime.changePower(50);
    driveForTime.execute();

    /*
     * Drive to corner
     */
    driveTilBump.changeHeading(270);
    driveTilBump.changeBumpDirection(RobotRight);
    driveTilBump.changePower(50);
    driveTilBump.execute();
}
