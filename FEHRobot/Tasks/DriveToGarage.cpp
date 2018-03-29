#include "DriveToGarage.h"

DriveToGarage::DriveToGarage(Robot *robot_):
    waitForLight(robot_),
    driveForTime(robot_, 0, 50, 1350),
    driveTilBump(robot_, 230, 50, RobotRight),
    driveToPosition(robot_, 0, 0),
    changeArmPosition(robot_, ArmUp, 500),
    turnForTime(robot_, 25, 0.0f),
    driveToLine(robot_, 35)
{
    robot = robot_;
}

StatusCode DriveToGarage::execute(){

    //driveForTime.setup(220, 70, 500);
    //driveForTime.execute();
    /*
     * Move To Ramp
     */
    //driveTilBump.setup(255, 80, RobotRight);
    //driveTilBump.execute();
    /*
    move towards ramp
    */
    driveForTime.setup(180, 100, 1100);
    driveForTime.execute();
    /*
     * Move To Ramp
     */
    driveForTime.setup(245, 100, 400);
    driveForTime.execute();

    driveForTime.setup(180, 100, 500);
    driveForTime.execute();

    /*
     * Go up ramp
     */
    driveForTime.setup(175, 100, 3000);
    driveForTime.execute();

    /*
     * Go towards garage
     */
    driveForTime.setup(182, 100, 900);
    driveForTime.execute();
    /*
     * Back away slightly
     */
    driveForTime.setup(0, 50, 200);
    driveForTime.execute();
    /*
     * Become parallel with garage door
     */
    turnForTime.setup(50, .50f);
    turnForTime.execute();

    /*
     * Move towards garage while parallel
     */
    driveForTime.setup(190, 70, 900);
    driveForTime.execute();

    /*
     * Lineup arm with garage door
     */
    driveToLine.changePower(45);
    driveToLine.execute();

    Sleep(300);

    return Success;
}

