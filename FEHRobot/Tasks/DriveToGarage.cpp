#include "DriveToGarage.h"

DriveToGarage::DriveToGarage(Robot *robot_):
    waitForLight(robot_),
    driveForTime(robot_, 0, 50, 1350),
    driveTilBump(robot_, 230, 50, RobotRight),
    driveToPosition(robot_, 0, 0),
    changeArmPosition(robot_, ArmUp, 500),
    turnForTime(robot, 25, 1100),
    driveToLine(robot_, 35)
{
    robot = robot_;
}

StatusCode DriveToGarage::execute(){

    driveForTime.setup(180, 70, 500);
    driveForTime.execute();
    /*
     * Move To Ramp
     */
    driveTilBump.setup(250, 70, RobotRight);
    driveTilBump.execute();

    /*
     * Go up ramp
     */
    driveForTime.setup(175, 100, 3000);
    driveForTime.execute();

    /*
     * Go towards garage
     */
    driveForTime.setup(180, 50, 2000);
    driveForTime.execute();
    /*
     * Back away slightly
     */
    driveForTime.setup(0, 50, 250);
    driveForTime.execute();
    /*
     * Become parallel with garage door
     */
    turnForTime.setup(25, 1200);
    turnForTime.execute();

    /*
     * Move towards garage while parallel
     */
    driveForTime.setup(180, 50, 1250);
    driveForTime.execute();

    /*
     * Lineup arm with garage door
     */
    driveToLine.changePower(35);
    driveToLine.execute();

    Sleep(500);

    return Success;
}

