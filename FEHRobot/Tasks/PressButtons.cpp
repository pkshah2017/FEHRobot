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

    logger -> logMessage("Changing Arm Position");
    ArmPosition buttonPosition = ArmRight;

    int turnIntoButtons =0;
    if(status == L_Red){
        buttonPosition = ArmRight;
        turnIntoButtons = -50;
        status = Success;
    } else if(status == L_Blue){
        buttonPosition = ArmLeft;
        turnIntoButtons = 25;
        status = Success;
    } else {
        status = E_UnreachableCode;
        logger -> logError(status);
    }
    changeArmPosition.setup(buttonPosition, 1.75f);
    changeArmPosition.execute();
    /*
     * Move To Buttons
     */
    logger -> logMessage("Moving forward to press buttons");
    driveForTime.setup(buttonPosition == ArmLeft ? 0 : 345, 70, 350);
    driveForTime.execute();

    /*
     * Hold Buttons
     */

    logger -> logMessage("Holding buttons for 5 seconds");
    waitForTime.changeDriveTime(5000);
    waitForTime.execute();

    /*
     * Turn to straighten out
     */

    logger -> logMessage("Turning out of buttons");
    turnForTime.setup(turnIntoButtons, .25f);
    turnForTime.execute();

    /*
     * Tap Buttons again
     */
    logger -> logMessage("Hitting buttons again");
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
    logger -> logMessage("Backing away from buttons");
    driveForTime.setup(180, 50, 250);
    driveForTime.execute();

    /*
     * Raise Arm
     */

    logger -> logMessage("Raising arms again");
    changeArmPosition.setup(ArmUp, 0.0f);
    changeArmPosition.execute();



    return Success;
}

