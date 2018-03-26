#include "Logger.h"
#include "DriveToButtons.h"

DriveToButtons::DriveToButtons(Robot *robot_):
    waitForLight(robot_),
    driveForTime(robot_, 0, 50, 1350),
    centerOnLine(robot_),
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
    driveForTime.setup(0, 50, 300);
    driveForTime.execute();

    /*
     * Drive to buttons
     */
    SD.Printf("Btn X: %f", robot->getLocationX(ButtonsLocation));
    LCD.WriteRC("Btn X: ", 7, 1);
    LCD.WriteRC(robot->getLocationX(ButtonsLocation),7,3);

    SD.Printf("Btn X: %f", robot->getLocationY(ButtonsLocation));
    LCD.WriteRC("Btn Y: ", 8, 1);
    LCD.WriteRC(robot->getLocationY(ButtonsLocation),8,3);
    driveToPosition.setup(robot->getLocationX(ButtonsLocation), robot->getLocationY(ButtonsLocation), 50);
    driveToPosition.execute();

    /*
     * Center on the line
     */
    centerOnLine.execute();

    return Success;
}
