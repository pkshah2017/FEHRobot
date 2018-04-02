#include "Logger.h"
#include "PressButtons.h"
#include "FEHLCD.h"
#include "FEHServo.h"


PressButtons::PressButtons(Robot *robot_):
    readButtonLight(robot_),
    driveForTime(robot_, 0, 50, 0),
    turnForTime(robot_, -25, 250),
    waitForTime(robot_, 2000),
    centerOnLine(robot_, 45),
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

    int turnIntoButtons = 0, turnPower =0;
    if(status == L_Red){
        buttonPosition = ArmRight;
        turnIntoButtons = -50;
        turnPower = -3;
        status = Success;
    } else if(status == L_Blue){
        buttonPosition = ArmLeft;
        turnIntoButtons = 40;
        turnPower = 2;
        status = Success;
    } else {
        status = E_UnreachableCode;
        logger -> logError(status);
    }
    changeArmPosition.setup(buttonPosition, 1.75f);
    changeArmPosition.execute();
    Sleep(300);
    /*
     * Move To Buttons
     */

    logger -> logMessage("Moving forward to press buttons");
    driveForTime.setup(buttonPosition == ArmLeft ? 30 : 315, 70, 500);
    driveForTime.execute();

    /*
    float startTime = TimeNow();
    while((TimeNow()-startTime<.40)){


       // (*robot).drive(356, 40);
        //centerOnLine.setup(15);
        //centerOnLine.execute();
    }*/

    /*
     * Hold Buttons
     */

    logger -> logMessage("Holding buttons for 5 seconds");
    //waitForTime.changeDriveTime(5000);
    //waitForTime.execute();
    /*
    startTime = TimeNow();
    while((TimeNow()-startTime<.5f)&&!(robot-> getDeadzoneStatus())){
        LCD.WriteRC(robot-> getDeadzoneStatus(),10,2);
        //driveForTime.setup(0, 20, 100);
        //driveForTime.execute();
        (*robot).driveAndTurn(0, 30, turnPower);
        (*robot).drive(0, 40);

    }*/


    /*
     * Turn to straighten out
     */

    //logger -> logMessage("Turning out of buttons");
    //turnForTime.setup(turnIntoButtons, .05f);
    //turnForTime.execute();

    /*
     * Tap Buttons again
     */
    //logger -> logMessage("Hitting buttons again");
    //driveForTime.setup(0, 50, 500);
    //driveForTime.execute();

    /*
     * Hold Buttons again if deadzone is still active
     */
   // waitForTime.changeDriveTime(robot-> getDeadzoneStatus() != 2 ? 00 : 0);
    //waitForTime.execute();

    /*
     * Back away from buttons
     */
    logger -> logMessage("Backing away from buttons");
    driveForTime.setup(180, 50, 200);
    driveForTime.execute();

    /*
     * Raise Arm
     */

    logger -> logMessage("Raising arms again");
    changeArmPosition.setup(ArmUp, 0.0f);
    changeArmPosition.execute();



    return Success;
}

