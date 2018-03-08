#include "PressButtons.h"
#include "FEHLCD.h"
#include "FEHServo.h"

FEHServo crankArm(FEHServo::Servo1);

//All commands are initalized assuming the light will be red
//If light is blue, values are modified in failure recovery
PressButtons::PressButtons(Robot &robot_):
    readButtonLight(robot_),
    driveForTime(robot_, 0, 50, 0),
    turnForTime(robot_, -25, 250),
    waitForTime(robot_, 2000),
    changeArmPosition(robot_, ArmRight, 1000),
    driveToPosition(robot_, 0, 0)
{
    robot = robot_;
    buttonColor = Red;
}

int PressButtons::execute(){
    /*
     * Read the button color
     */
    buttonColor = static_cast<ButtonColor>(readButtonLight.execute());
    /*
     * Change the arm position to press the button
     */
    ArmPosition buttonPosition = buttonColor == Blue ? ArmLeft : ArmRight;
    changeArmPosition.selectArmPosition(buttonPosition);
    changeArmPosition.selectWaitTime(1000);
    changeArmPosition.execute();
    /*
     * Move To Buttons
     */
    driveForTime.changeHeading(0);
    driveForTime.changePower(70);
    driveForTime.changeDriveTime(350);
    driveForTime.execute();

    /*
     * Turn Into Buttons
     */
    //    turnForTime.changePower(buttonColor == Red ? -25 : 25);
    //    turnForTime.changeDriveTime(250);
    //    turnForTime.execute();

    /*
     * Hold Buttons
     */
    waitForTime.changeDriveTime(5000);
    waitForTime.execute();

    /*
     * Back away slightly
     */
    //    driveForTime.changeHeading(180);
    //    driveForTime.changePower(50);
    //    driveForTime.changeDriveTime(150);
    //    driveForTime.execute();

    /*
     * Hit buttons again
     */
    //    driveForTime.changeHeading(0);
    //    driveForTime.changePower(50);
    //    driveForTime.changeDriveTime(350);
    //    driveForTime.execute();

    /*
     * Back away from buttons
     */
    driveForTime.changeHeading(180);
    driveForTime.changePower(50);
    driveForTime.changeDriveTime(250);
    driveForTime.execute();

    /*
     * Raise Arm
     */
    changeArmPosition.selectArmPosition(ArmUp);
    changeArmPosition.selectWaitTime(0);
    changeArmPosition.execute();

    /*
     * Move To Bottom of Ramp
     */
    driveToPosition.changeXSetpoint(29);
    driveToPosition.changeYSetpoint(23.4);
    driveToPosition.execute();

    /*
     * Move up Ramp
     */
    driveForTime.changeHeading(180);
    driveForTime.changePower(70);
    driveForTime.changeDriveTime(4500);
    driveForTime.execute();

    /*
     * Move To Center of Top Level
     */
    driveToPosition.changeXSetpoint(17.3);
    driveToPosition.changeYSetpoint(58.8);
    driveToPosition.execute();

    /*
    * Turn towards crank
    */
    turnForTime.changePower(25);
    turnForTime.changeDriveTime(800);
    turnForTime.execute();

    /*
    * Go To Crank
    */
    driveToPosition.changeXSetpoint(24.8);
    driveToPosition.changeYSetpoint(66.3);
    driveToPosition.execute();

    /*
     * Turn the crank
     */
    robot.updateRPSStates();
    int fuelType = robot.getFuelType();
    crankArm.SetDegree(fuelType == 1 ? 0 : 180);
    Sleep(2.0);
    crankArm.SetDegree(fuelType == 1 ? 180 : 0);

    /*
     * Move To Center of Top Level
     */
    driveToPosition.changeXSetpoint(17.3);
    driveToPosition.changeYSetpoint(58.8);
    driveToPosition.execute();

    /*
    * Go Towards the top of the ramp
    */
    driveToPosition.changeXSetpoint(31.8);
    driveToPosition.changeYSetpoint(41.9);
    driveToPosition.execute();

    /*
     * Move down Ramp
     */
    driveToPosition.changeXSetpoint(31.8);
    driveToPosition.changeYSetpoint(21.9);
    driveToPosition.execute();

    /*
     * Move to outside start
     */
    driveToPosition.changeXSetpoint(17);
    driveToPosition.changeYSetpoint(21.5);
    driveToPosition.execute();

    /*
     * Move to start
     */
    driveToPosition.changeXSetpoint(17.7);
    driveToPosition.changeYSetpoint(30);
    driveToPosition.execute();

    return 0;
}

