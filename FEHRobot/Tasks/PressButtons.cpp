#include "PressButtons.h"
#include "FEHLCD.h"

//All commands are initalized assuming the light will be red
//If light is blue, values are modified in failure recovery
PressButtons::PressButtons(Robot &robot_):
    readButtonLight(robot_),
    driveForTime(robot_, 0, 50, 0),
    turnForTime(robot_, -25, 250),
    waitForTime(robot_, 2000),
    changeArmPosition(robot_, ArmRight, 1000)
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
    driveForTime.changeHeading(buttonColor == Red ? 340 : 10);
    driveForTime.changePower(50);
    driveForTime.changeDriveTime(500);
    driveForTime.execute();

    /*
     * Turn Into Buttons
     */
    turnForTime.changePower(buttonColor == Red ? -25 : 25);
    turnForTime.changeDriveTime(250);
    turnForTime.execute();

    /*
     * Hold Buttons
     */
    waitForTime.changeDriveTime(2000);

    /*
     * Back away slightly
     */
    driveForTime.changeHeading(180);
    driveForTime.changePower(50);
    driveForTime.changeDriveTime(150);
    driveForTime.execute();

    /*
     * Hit buttons again
     */
    driveForTime.changeHeading(0);
    driveForTime.changePower(50);
    driveForTime.changeDriveTime(350);
    driveForTime.execute();

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
     * Move To Wrench
     */
    driveForTime.changeHeading(270);
    driveForTime.changePower(50);
    driveForTime.changeDriveTime(3800);
    driveForTime.execute();

    /*
     * Lower Arm on wrench
     */
    changeArmPosition.selectArmPosition(ArmRight);
    changeArmPosition.selectWaitTime(1000);
    changeArmPosition.execute();

    /*
    * Raise Arm with wrench
    */
    changeArmPosition.selectArmPosition(ArmUp);
    changeArmPosition.selectWaitTime(1000);
    changeArmPosition.execute();

    /*
    * Move Toward Finish
    */
    driveForTime.changeHeading(90);
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

