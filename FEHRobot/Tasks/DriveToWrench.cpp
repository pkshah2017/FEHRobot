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
    turnToHeadingZero(robot_, 25),
    turnForTime(robot_,50,50),
    backupToLineSingleOpto(robot_, 40),
    backupOffLineSingleOpto(robot_, 40)
{
    robot = robot_;
}

StatusCode DriveToWrench::execute(){
    /*
     * Drive to wrench
     */
    (*robot).updateRPSStates();
    driveForTime.setup(90, 80, 1.0f);
    driveForTime.execute();

    logger -> logMessage("Moving towards wrench");
    driveForTime.setup(269, 100, 1.3f);
    driveForTime.execute();

    alignWithWrench();

    return Success;
}

void DriveToWrench::alignWithWrench(){
    logger->logMessage("Moving To RPS location in front of line");
    driveToPosition.setup(robot->getLocationX(Wrench_Pickup), robot->getLocationY(Wrench_Pickup), 40);
    StatusCode errorStatus = driveToPosition.execute();

    logger->logMessage("Drive To RPS in front of wrench status: ");
    logger->logError(errorStatus);
    if (errorStatus == E_Timeout)
    {
        logger->logMessage("Recovering from RPS failure");
        (*robot).stop();
        Sleep(150);
        (*robot).updateRPSStates();
        if(((int)(*robot).getCurrentHeading()>2) && ((int)(*robot).getCurrentHeading()<60))
        {
            turnForTime.setup(30,100+10*((int)(*robot).getCurrentHeading()));
            turnForTime.execute();
        }
        else if(((int)(*robot).getCurrentHeading()<358) && ((int)(*robot).getCurrentHeading()>300))
        {
            turnForTime.setup(-30,100+10*(360-(int)(*robot).getCurrentHeading()));
            turnForTime.execute();
        }

        logger->logMessage("Moving away from potential wrench collision");
        driveForTime.setup(90, 80, .2f);
        driveForTime.execute();

        alignWithWrench();
        return;
    }

    logger -> logMessage("Backup onto the wrench line");
    backupToLineSingleOpto.changePower(40);
    errorStatus = backupToLineSingleOpto.execute();
    if(errorStatus == E_Timeout){
        logger->logMessage("Moving away from potential wrench collision");
        driveForTime.setup(90, 80, .2f);
        driveForTime.execute();

        alignWithWrench();
        return;
     }

    logger -> logMessage("Backup off the wrench line");
    backupOffLineSingleOpto.changePower(40);
    backupOffLineSingleOpto.execute();

    driveForTime.setup(0, 70, 50);
    driveForTime.execute();

    logger->logMessage("Trying to hit bump");
    driveTilBump.setup(272, 60, RobotRight);
    errorStatus = driveTilBump.execute();

    logger->logMessage("Final approach of wrench status: ");
    logger->logError(errorStatus);
    if(errorStatus == E_Timeout)
    {
        logger->logMessageScreen("Drive till Bump Failed");
        logger->logMessage("Recovering from driving til bump of wrench holder failure");

        logger->logMessage("Moving away from potential wrench collision");
        driveForTime.setup(90, 80, .2f);
        driveForTime.execute();

        logger->logMessage("Turning to realign RPS");
        turnForTime.setup(30,70);
        turnForTime.execute();

        alignWithWrench();
        return;
    }

    Sleep(50);
    turnForTime.setup(30,20);
    turnForTime.execute();

    logger -> logMessage("Lining up to wrench");
}
