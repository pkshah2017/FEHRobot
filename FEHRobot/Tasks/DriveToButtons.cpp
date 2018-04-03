#include "Logger.h"
#include "DriveToButtons.h"
#include "Constants.h"

DriveToButtons::DriveToButtons(Robot *robot_):
    waitForLight(robot_),
    driveForTime(robot_, 0, 50, 1350),
    centerOnLine(robot_,43),
    turnForTime(robot_,45,.05f),
    changeArmPosition(robot_, ArmUp, 0),
    driveToPosition(robot_, 0.0f, 0.0f)

{
    robot = robot_;
}

StatusCode DriveToButtons::execute(){
    /*
     * Wait for start light
     */
    waitForLight.execute();

    /*
     * Drive out of start
     */
    logger -> logMessage("Driving out of Start");
    driveForTime.setup(0, 50, 1300);
    driveForTime.execute();
    /*
     * fix arm position
     */
    changeArmPosition.setup(ArmUp, 0.0f);
    changeArmPosition.execute();
    /*
     * Drive to buttons
     */

    //SD.Printf("Btn X: %f", robot->getLocationX(ButtonsLocation));
    //LCD.WriteRC("Btn X: ", 7, 1);
    //LCD.WriteRC(robot->getLocationX(ButtonsLocation),7,3);

    //SD.Printf("Btn X: %f", robot->getLocationY(ButtonsLocation));
    //LCD.WriteRC("Btn Y: ", 8, 1);
    //LCD.WriteRC(robot->getLocationY(ButtonsLocation),8,3);
    //driveToPosition.setup(robot->getLocationX(ButtonsLocation), robot->getLocationY(ButtonsLocation), 50);
    //driveToPosition.execute();


    turnForTime.setup(-30,50);
    turnForTime.execute();
    Sleep(50);

    logger -> logMessage("Moving left to the button first line");
    centerOnLine.execute();
   // centerOnLine.execute();

    turnForTime.setup(-30,100);
    turnForTime.execute();
    Sleep(50);
    logger -> logMessage("Moving left over the button first line");
    driveForTime.setup(90, 45, 450);
    driveForTime.execute();
    turnForTime.setup(-30,50);
    turnForTime.execute();
    Sleep(50);

    /*
     * Center on the line
     */

    logger -> logMessage("Centering on button line");
    centerOnLine.execute();

    return Success;
}
