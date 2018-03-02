#include "DriveToJack.h"

DriveToJack::DriveToJack(Robot &robot_):
    waitForLight(robot_),
    driveForTime(robot_, 0, 50, 1000),
    driveTilBump(robot_, 315, 50, RobotFront)
{
}

int DriveToJack::execute(){
    /*
     * Wait for start light
     */
    waitForLight.execute();

    /*
     * Drive out of start
     */
    driveForTime.execute();

    /*
     * Drive to wall
     */
    driveTilBump.execute();

    /*
     * Drive to corner
     */
    driveTilBump.changeHeading(270);
    driveTilBump.changeBumpDirection(RobotRight);
    driveTilBump.execute();

}
