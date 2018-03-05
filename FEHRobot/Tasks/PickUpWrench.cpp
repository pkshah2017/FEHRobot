#include "PickUpWrench.h"
#include "FEHLCD.h"
#include <FEHUtility.h>

//All commands are initalized assuming the light will be red
//If light is blue, values are modified in failure recovery
PickUpWrench::PickUpWrench(Robot &robot_):
    driveForTime(robot_, 0, 50, 0),
    turnForTime(robot_, -25, 250),
    waitForTime(robot_, 2000),
    changeArmPosition(robot_, ArmRight, 1000),
    driveTilBump(robot_, 270, 50, RobotLeft),
    driveToLine(robot_, 35)
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
     * Change the arm position to slightly raised
     */
    changeArmPosition.selectArmPosition(ArmSlightlyRaised);
    changeArmPosition.selectWaitTime(0);
    changeArmPosition.execute();
    /*
     * Back away from wrench stand
     */
    driveForTime.changeHeading(90);
    driveForTime.changePower(50);
    driveForTime.changeDriveTime(500);
    driveForTime.execute();
    /*
     * Raise arm to pickup wrench
     */
    changeArmPosition.selectArmPosition(ArmUp);
    changeArmPosition.selectWaitTime(2000);
    changeArmPosition.execute();
    /*
     * Move To Ramp
     */
    driveTilBump.changeHeading(230);
    driveTilBump.changePower(50);
    driveTilBump.changeBumpDirection(RobotRight);
    driveTilBump.execute();

    /*
     * Go up ramp
     */
    driveForTime.changeHeading(175);
    driveForTime.changePower(75);
    driveForTime.changeDriveTime(4000);
    driveForTime.execute();

    /*
     * Go towards garage
     */

    driveForTime.changeHeading(180);
    driveForTime.changePower(50);
    driveForTime.changeDriveTime(2000);
    driveForTime.execute();

    /*
     * Become parallel with garage door
     */
    turnForTime.changeDriveTime(1100);
    turnForTime.changePower(25);
    turnForTime.execute();

    /*
     * Move towards garage while parallel
     */
    driveForTime.changeHeading(180);
    driveForTime.changePower(50);
    driveForTime.changeDriveTime(1150);
    driveForTime.execute();
    /*
     * Lineup arm with garage door
     */

    driveToLine.execute();
    Sleep(500);

    /*
     * Slightly lower arm
     */
    changeArmPosition.selectArmPosition(ArmAngledRight);
    changeArmPosition.selectWaitTime(1500);
    changeArmPosition.execute();

    /*
     * Enter garage
     */

    driveForTime.changeHeading(270);
    driveForTime.changePower(50);
    driveForTime.changeDriveTime(1000);
    driveForTime.execute();

    /*
     * Lower Arm
     */
    changeArmPosition.selectArmPosition(ArmRight);
    changeArmPosition.selectWaitTime(1500);
    changeArmPosition.execute();

    /*
     * Exit garage
     */
    driveForTime.changeHeading(90);
    driveForTime.changePower(50);
    driveForTime.changeDriveTime(1800);
    driveForTime.execute();

    /*
     * Hit Fuel Crank
     */
    driveForTime.changeHeading(180);
    driveForTime.changePower(50);
    driveForTime.changeDriveTime(1900);
    driveForTime.execute();


//    /*
//     * Turn to Face side ramp wall
//     */
//    turnForTime.changeDriveTime(500);
//    turnForTime.changePower(25);
//    turnForTime.execute();

//    /*
//     * Run into side ramp wall
//     */
//    driveTilBump.changeBumpDirection(RobotLeft);
//    driveTilBump.changeHeading(90);
//    driveTilBump.changePower(50);
//    driveTilBump.execute();

//    /*
//    * Go down side ramp
//    */
//    driveForTime.changeHeading(0);
//    driveForTime.changePower(50);
//    driveForTime.changeDriveTime(1250);
//    driveForTime.execute();

//    /*
//    * Move Toward Finish
//    */
//    driveForTime.changeHeading(270);
//    driveForTime.changePower(50);
//    driveForTime.changeDriveTime(2250);
//    driveForTime.execute();

//    /*
//    * Hit final button
//    */
//    driveForTime.changeHeading(180);
//    driveForTime.changePower(50);
//    driveForTime.changeDriveTime(1950);
//    driveForTime.execute();

    return 0;
}

