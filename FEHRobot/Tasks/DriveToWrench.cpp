#include "Logger.h"
#include "DriveToWrench.h"
#include "FEHLCD.h"

DriveToWrench::DriveToWrench(Robot *robot_):
    waitForLight(robot_),
    driveForTime(robot_, 0, 50, 1350),
    driveToPosition(robot_, 0, 0),
    changeArmPosition(robot_, ArmUp, 500),
    driveToPositionWithHeading(robot_, 0, 0, 315),    
    driveTilBump(robot_, 270, 50, RobotLeft),
    backupToLine(robot_, 30),
    turnToHeadingZero(robot_, 25)
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


    logger -> logMessage("Moving towards wrench");
    //driveForTime.setup(193, 40, 2.35f);
    //driveForTime.execute();
    driveForTime.setup(277, 80, 1.2f);
    driveForTime.execute();



    logger -> logMessage("Final approach of wrench");
    driveTilBump.setup(273, 60, RobotRight);
    driveTilBump.execute();

    logger -> logMessage("Lining up to wrench");
    turnToHeadingZero.setup(15);
    turnToHeadingZero.execute();

    //logger -> logMessage("Lining up with wrench line");
    //backupToLine.execute();

    //logger -> logMessage("Move away from wrench");
    //driveForTime.setup(90, 40, .35f);
    //driveForTime.execute();

    //driveToPositionWithHeading.setup(7.5f, 19.75f, 0);
    //driveToPositionWithHeading.execute();
    //(*robot).updateRPSStates();
    //LCD.WriteRC("LOCATION X and Y: ", 6, 1);
    //LCD.WriteRC((*robot).getX(), 7, 1);
    //LCD.WriteRC((*robot).getY(), 8, 1);


    return Success;
}

