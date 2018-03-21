#include "DriveToJack.h"

DriveToJack::DriveToJack(Robot *robot_):
    driveForTime(robot_, 0, 50, 1000),
    driveToPosition(robot_,0,0),
    driveTilBump(robot_, 315, 50, RobotFront),
    turnForTime(robot_, 0, 0)
{
    robot = robot_;
}

StatusCode DriveToJack::execute(){


    /*
     * Drive towards wrench/start/jack
     */
    //driveForTime.setup(270, 50, 1700);
    //driveForTime.execute();
    driveToPosition.setup(12.0f,21.5f);
    driveToPosition.execute();
    driveToPosition.setup(9.0f,15.0f);
    driveToPosition.execute();

    /*
     * Drive to Wall
     */
    driveForTime.setup(345, 80, 700);
    driveForTime.execute();

    /*
     * Drive to corner
     */
    driveTilBump.setup(270, 80, RobotRight);
    driveTilBump.execute();

    return Success;
}
