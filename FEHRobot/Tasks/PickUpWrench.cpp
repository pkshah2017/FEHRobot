#include "PickUpWrench.h"
#include "FEHLCD.h"

//All commands are initalized assuming the light will be red
//If light is blue, values are modified in failure recovery
PickUpWrench::PickUpWrench(Robot &robot_):
    driveForTime(robot_, 0, 50, 0),
    turnForTime(robot_, -25, 250),
    waitForTime(robot_, 2000),
    changeArmPosition(robot_, ArmRight, 1000),
    driveTilBump(robot_, 270, 50, RobotLeft)
{
    robot = robot_;
}

int PickUpWrench::execute(){
    /*
     * Change the arm position to grab wrench
     */
    changeArmPosition.selectArmPosition(ArmRight);
    changeArmPosition.selectWaitTime(2000);
    changeArmPosition.execute();
    /*
     * Raise arm to pickup wrench
     */
    changeArmPosition.selectArmPosition(ArmUp);
    changeArmPosition.selectWaitTime(2000);
    changeArmPosition.execute();
    /*
     * Move To Ramp
     */
    driveForTime.changeHeading(180);
    driveForTime.changePower(50);
    driveForTime.changeDriveTime(500);
    driveForTime.execute();

    /*
     * Go up ramp
     */
    driveForTime.changeHeading(180);
    driveForTime.changePower(65);
    driveForTime.changeDriveTime(1000);
    driveForTime.execute();

    /*
     * Go towards garage
     */

    driveForTime.changeHeading(180);
    driveForTime.changePower(50);
    driveForTime.changeDriveTime(1000);
    driveForTime.execute();

    /*
     * Become parallel with garage door
     */
    turnForTime.changeDriveTime(500);
    turnForTime.changePower(25);
    turnForTime.execute();

    /*
     * Lineup arm with garage door
     */
    driveForTime.changeHeading(0);
    driveForTime.changePower(50);
    driveForTime.changeDriveTime(350);
    driveForTime.execute();

    /*
     * Slightly lower arm
     */
    changeArmPosition.selectArmPosition(ArmAngledRight);
    changeArmPosition.selectWaitTime(500);
    changeArmPosition.execute();

    /*
     * Enter garage
     */
    driveForTime.changeHeading(270);
    driveForTime.changePower(50);
    driveForTime.changeDriveTime(750);
    driveForTime.execute();

    /*
     * Lower Arm
     */
    changeArmPosition.selectArmPosition(ArmRight);
    changeArmPosition.selectWaitTime(0);
    changeArmPosition.execute();

    /*
     * Exit garage
     */
    driveForTime.changeHeading(270);
    driveForTime.changePower(50);
    driveForTime.changeDriveTime(4750);
    driveForTime.execute();

    /*
     * Turn to Face side ramp wall
     */
    turnForTime.changeDriveTime(500);
    turnForTime.changePower(25);
    turnForTime.execute();

    /*
     * Run into side ramp wall
     */
    driveTilBump.changeBumpDirection(RobotLeft);
    driveTilBump.changeHeading(90);
    driveTilBump.changePower(50);
    driveTilBump.execute();

    /*
    * Go down side ramp
    */
    driveForTime.changeHeading(0);
    driveForTime.changePower(50);
    driveForTime.changeDriveTime(1250);
    driveForTime.execute();

    /*
    * Move Toward Finish
    */
    driveForTime.changeHeading(270);
    driveForTime.changePower(50);
    driveForTime.changeDriveTime(2250);
    driveForTime.execute();

    /*
    * Hit final button
    */
    driveForTime.changeHeading(180);
    driveForTime.changePower(50);
    driveForTime.changeDriveTime(1950);
    driveForTime.execute();

    return 0;
}

