#include "Logger.h"
#include "DriveToEnd.h"
#include "FEHIO.h"

DriveToEnd::DriveToEnd(Robot *robot_):
    waitForLight(robot_),
    driveForTime(robot_, 0, 50, 1350),
    driveToPosition(robot_, 0, 0),
    changeArmPosition(robot_, ArmUp, 100),
    changeCrankArmPosition(robot_, ArmUp, 100),
    turnForTime(robot_, 0, 0)
{
    robot = robot_;
}

StatusCode DriveToEnd::execute(){

    /*
     * Move To Center of Top Level
     */
    //driveToPosition.setup(17.3f, 58.8f, 80);
    //driveToPosition.execute();
    driveForTime.setup(0,100,400);
    driveForTime.execute();

    driveForTime.setup(45,80,500);
    driveForTime.execute();

    changeArmPosition.selectArmPosition(ArmUp);
    changeArmPosition.execute();
    changeCrankArmPosition.selectArmPosition(ArmUp);
    changeCrankArmPosition.execute();

    float startTime = TimeNow();
    logger->logMessage("Doing Turn and Drive Away");
    while((TimeNow()-startTime<3.0f) && (*robot).getLimit(RobotLeft)){
        (*robot).updateSensorStates();
        logger->logWorldState();
        (*robot).driveAndTurn(55, 90, -22);
        Sleep(REFRESH_RATE);
    }
    /*
     * Rotate Clockwise
     */
    //turnForTime.setup(-50, .4f);
    // turnForTime.execute();

    /*
     * Go Towards the top of the ramp
     */
    driveForTime.setup(65,90,400);
    driveForTime.execute();
    // driveToPosition.setup(31.8f, 41.9f, 60);
    // driveToPosition.execute();

    /*
     * Move down Ramp
     */
    // driveToPosition.setup(31.8f, 29.0f, 60);
    // driveToPosition.execute();
    driveForTime.setup(0,100,1450);
    driveForTime.execute();

    /*
     * Move to outside start
     */
    //  driveToPosition.setup(21.0f, 21.5f, 60);
    // driveToPosition.execute();
    driveForTime.setup(270,100,1000);
    driveForTime.execute();

    /*
     * Move to start
     */
    // driveToPosition.setup(17.7f, 30.0f, 60);
    // driveToPosition.execute();
    driveForTime.setup(180,100,1600);
    driveForTime.execute();

    return Success;
}

