#include "Logger.h"
#include "PressButtons.h"
#include "FEHLCD.h"
#include "FEHServo.h"


PressButtons::PressButtons(Robot *robot_):
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
    ArmPosition buttonPosition = ArmRight;

    int turnIntoButtons =0;
    if(status == L_Red){
        buttonPosition = ArmRight;
        turnIntoButtons = -25;
        status = Success;
    } else if(status == L_Blue){
        buttonPosition = ArmLeft;
        turnIntoButtons = 25;
        status = Success;
    } else {
        status = E_UnreachableCode;
        logger -> logError(status);
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
     * Turn to straighten out
     */
    turnForTime.setup(turnIntoButtons, .20f);
    turnForTime.execute();

    /*
     * Tap Buttons again
     */
    driveForTime.setup(0, 50, 350);
    driveForTime.execute();

    /*
     * Hold Buttons again if deadzone is still active
     */
    waitForTime.changeDriveTime(robot-> getDeadzoneStatus() != 2 ? 00 : 0);
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



    return Success;
}

