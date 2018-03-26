#include "Logger.h"
#include "DriveToWrench.h"
#include "FEHLCD.h"

DriveToWrench::DriveToWrench(Robot *robot_):
    waitForLight(robot_),
    driveForTime(robot_, 0, 50, 1350),
    driveToPosition(robot_, 0, 0),
    changeArmPosition(robot_, ArmUp, 500),
    driveToPositionWithHeading(robot_, 0, 0, 315),
    backupToLine(robot_, 30)
{
    robot = robot_;
}

StatusCode DriveToWrench::execute(){
    /*
     * Drive to wrench
     */
    //driveToPosition.setup(7.5f, 21.0f);
    //driveToPosition.execute();
    (*robot).updateRPSStates();


    /*
    SD.Printf("Btn X: %f", robot->getLocationX(Wrench_Pickup));
    LCD.WriteRC("Btn X: ", 7, 1);
    LCD.WriteRC(robot->getLocationX(Wrench_Pickup),7,3);

    SD.Printf("Btn X: %f", robot->getLocationY(Wrench_Pickup));
    LCD.WriteRC("Btn Y: ", 8, 1);
    LCD.WriteRC(robot->getLocationY(Wrench_Pickup),8,3);
    */

    //driveToPosition.setup(robot->getLocationX(Wrench_Pickup), robot->getLocationY(Wrench_Pickup), 50);
    //driveToPosition.execute();

    driveForTime.setup(193, 40, 2.35f);
    driveForTime.execute();

    backupToLine.execute();


    //driveToPositionWithHeading.setup(7.5f, 19.75f, 0);
    //driveToPositionWithHeading.execute();
    (*robot).updateRPSStates();
    LCD.WriteRC("LOCATION X and Y: ", 6, 1);
    LCD.WriteRC((*robot).getX(), 7, 1);
    LCD.WriteRC((*robot).getY(), 8, 1);


    return Success;
}

