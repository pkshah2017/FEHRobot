#include "Logger.h"
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
    logger -> logMessage("Driving towards center of lower level");
    driveForTime.setup(270, 50, 2700);
    driveForTime.execute();
    //driveToPosition.setup(12.0f,21.5f);
    //driveToPosition.execute();
    //driveToPosition.setup(8.0f,16.0f);
    //driveToPosition.execute();

    /*
     * Drive to Wall
     */

    logger -> logMessage("Driving to the wall");
    driveForTime.setup(340, 80, 1800);
    driveForTime.execute();


    logger -> logMessage("Backing away from wall");
    driveForTime.setup(180, 50, 100);
    driveForTime.execute();

    /*
     * Drive to corner
     */
    //driveTilBump.setup(270, 80, RobotRight);
    //driveTilBump.execute();

    return Success;
}
