#include "Logger.h"
#include "DriveToGarage.h"

DriveToGarage::DriveToGarage(Robot *robot_):
    waitForLight(robot_),
    driveForTime(robot_, 0, 50, 1350),
    driveTilBump(robot_, 230, 50, RobotRight),
    driveToPosition(robot_, 0, 0),
    changeArmPosition(robot_, ArmUp, 500),
    turnForTime(robot_, 25, 0.0f),
    driveToLine(robot_, 35),
    backupToWhiteLine(robot_, 25)
{
    robot = robot_;
}

StatusCode DriveToGarage::execute(){

    //driveForTime.setup(220, 70, 500);
    //driveForTime.execute();
    /*
     * Move To Ramp
     */
    //driveTilBump.setup(255, 80, RobotRight);
    //driveTilBump.execute();
    /*
    move towards ramp
    */
    driveForTime.setup(180, 100, 1250);
    driveForTime.execute();
    /*
     * Move To Ramp
     */
    driveForTime.setup(264, 100, 750);
    driveForTime.execute();

    driveForTime.setup(185, 100, 900);
    driveForTime.execute();

    /*
     * Go up ramp
     */
    driveForTime.setup(183, 100, 2500);
    driveForTime.execute();

    /*
     * Go towards garage
     */
    driveForTime.setup(90, 100, 170);
    driveForTime.execute();

    float startTime = TimeNow();
    //worked 1.2
    while(TimeNow()-startTime<1.1){
    (*robot).driveAndTurn(170, 90, 17);
    }

    /*
     * Back away slightly
     */
    //driveForTime.setup(0, 50, 200);
    //driveForTime.execute();
    /*
     * Become parallel with garage door
     */
    //turnForTime.setup(50, .30f);
    //turnForTime.execute();


    /*
     * Move towards garage while parallel
     */
    //worked 100
    driveForTime.setup(300, 70, 230);
    driveForTime.execute();


    backupToWhiteLine.changePower(45);
    backupToWhiteLine.execute();
    /*
     * Lineup arm with garage door
     */
    driveToLine.changePower(45);
    StatusCode status = driveToLine.execute();
    logger->logMessage("Lining up with Garage Status");
    logger->logError(status);
    if(status == E_Timeout){
        logger->logMessage("Lining up with Garage failed");

        logger->logMessage("Moving forward to cross black line");
       // driveForTime.setup(0, 70, 600);
       // driveForTime.execute();

        float startTime = TimeNow();
        //worked 1.2
        while(TimeNow()-startTime<700){
        (*robot).driveAndTurn(315, 70, -10);
        }

        logger->logMessage("Backing up onto the line");
        driveToLine.changePower(45);
        StatusCode status = driveToLine.execute();
    }

    return Success;
}

