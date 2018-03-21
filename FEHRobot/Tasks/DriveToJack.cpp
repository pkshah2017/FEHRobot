#include "DriveToJack.h"

DriveToJack::DriveToJack(Robot *robot_):
    driveForTime(robot_, 0, 50, 1000),
    driveTilBump(robot_, 315, 50, RobotFront)
{
    robot = robot_;
}

StatusCode DriveToJack::execute(){


    /*
     * Drive towards wrench/start/jack
     */
    driveForTime.setup(270, 50, 1500);
    driveForTime.execute();

    /*
     * Drive to Wall
     */
    driveForTime.setup(315, 50, 3500);
    driveForTime.execute();

    /*
     * Drive to corner
     */
    driveTilBump.setup(270, 50, RobotRight);
    driveTilBump.execute();

    return Success;
}
