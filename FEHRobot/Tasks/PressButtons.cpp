#include "PressButtons.h"
#include "FEHLCD.h"
#include "FEHServo.h"


PressButtons::PressButtons(Robot &robot_):
    readButtonLight(robot_),
    driveForTime(robot_, 0, 50, 0),
    turnForTime(robot_, -25, 250),
    waitForTime(robot_, 2000),
    changeArmPosition(robot_, ArmRight, 1000),
    driveToPosition(robot_, 0, 0)
{
    robot = robot_;
}

StatusCode PressButtons::execute(){
    StatusCode status;
    /*
     * Read the button color
     */
    status = readButtonLight.execute();
    /*
     * Change the arm position to press the button
     */
    ArmPosition buttonPosition;
    if(status == L_Red){
        buttonPosition = ArmRight;
    } else if(status == L_Blue){
        buttonPosition = ArmLeft;
    } else {
        status = E_UnreachableCode;
    }
    changeArmPosition.setup(buttonPosition, 1.0f);
    changeArmPosition.execute();
    /*
     * Move To Buttons
     */
    driveForTime.setup(0, 70, 350);
    driveForTime.execute();

    /*
     * Hold Buttons
     */
    waitForTime.changeDriveTime(5000);
    waitForTime.execute();

    /*
     * Back away from buttons
     */
    driveForTime.setup(180, 50, 250);
    driveForTime.execute();

    /*
     * Raise Arm
     */
    changeArmPosition.setup(ArmUp, 0.0f);
    changeArmPosition.execute();

//    /*
//     * Move To Bottom of Ramp
//     */

//    driveToPosition.changeXSetpoint(29);
//    driveToPosition.changeYSetpoint(23.4);
//    driveToPosition.execute();

//    /*
//     * Move up Ramp
//     */
//    driveForTime.changeHeading(180);
//    driveForTime.changePower(70);
//    driveForTime.changeDriveTime(4500);
//    driveForTime.execute();

//    /*
//     * Move To Center of Top Level
//     */
//    driveToPosition.changeXSetpoint(17.3);
//    driveToPosition.changeYSetpoint(58.8);
//    driveToPosition.execute();

//    /*
//    * Turn towards crank
//    */
//    turnForTime.changePower(25);
//    turnForTime.changeDriveTime(800);
//    turnForTime.execute();

//    /*
//    * Go To Crank
//    */
//    driveToPosition.changeXSetpoint(24.8);
//    driveToPosition.changeYSetpoint(66.3);
//    driveToPosition.execute();


//    /*
//     * Turn the crank
//     */
////    robot.updateRPSStates();
////    int fuelType = robot.getFuelType();
////    crankArm.SetDegree(fuelType == 1 ? 0 : 180);
////    Sleep(2.0);
////    crankArm.SetDegree(fuelType == 1 ? 180 : 0);

//    /*
//     * Move To Center of Top Level
//     */
//    driveToPosition.changeXSetpoint(17.3);
//    driveToPosition.changeYSetpoint(58.8);
//    driveToPosition.execute();

//    /*
//    * Go Towards the top of the ramp
//    */
//    driveToPosition.changeXSetpoint(31.8);
//    driveToPosition.changeYSetpoint(41.9);
//    driveToPosition.execute();

//    /*
//     * Move down Ramp
//     */
//    driveToPosition.changeXSetpoint(31.8);
//    driveToPosition.changeYSetpoint(21.9);
//    driveToPosition.execute();

//    /*
//     * Move to outside start
//     */
//    driveToPosition.changeXSetpoint(17);
//    driveToPosition.changeYSetpoint(21.5);
//    driveToPosition.execute();

//    /*
//     * Move to start
//     */
//    driveToPosition.changeXSetpoint(17.7);
//    driveToPosition.changeYSetpoint(30);
//    driveToPosition.execute();

//    /*
//     * Code Below was for a PT Test.
//     * Remove once the actual full run code is developed.
//     * It is left in as a reference if needed.
//     */

////    /*
////     * Move To Wrench
////     */
////    driveForTime.changeHeading(270);
////    driveForTime.changePower(50);
////    driveForTime.changeDriveTime(3800);
////    driveForTime.execute();

////    /*
////     * Lower Arm on wrench
////     */
////    changeArmPosition.selectArmPosition(ArmRight);
////    changeArmPosition.selectWaitTime(1000);
////    changeArmPosition.execute();

////    /*
////    * Raise Arm with wrench
////    */
////    changeArmPosition.selectArmPosition(ArmUp);
////    changeArmPosition.selectWaitTime(1000);
////    changeArmPosition.execute();

////    /*
////    * Move Toward Finish
////    */
////    driveForTime.changeHeading(90);
////    driveForTime.changePower(50);
////    driveForTime.changeDriveTime(2250);
////    driveForTime.execute();

////    /*
////    * Hit final button
////    */
////    driveForTime.changeHeading(180);
////    driveForTime.changePower(50);
////    driveForTime.changeDriveTime(1950);
////    driveForTime.execute();

    return Success;
}

