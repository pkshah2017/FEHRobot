#include "Logger.h"
#include "PickUpWrench.h"
#include "FEHLCD.h"
#include <FEHUtility.h>

//All commands are initalized assuming the light will be red
//If light is blue, values are modified in failure recovery
PickUpWrench::PickUpWrench(Robot *robot_):
    driveForTime(robot_, 0, 50, 0),
    turnForTime(robot_, -25, 250),
    waitForTime(robot_, 2000),
    changeArmPosition(robot_, ArmRight, 1000),
    driveTilBump(robot_, 270, 50, RobotLeft),
    driveToLine(robot_, 35)
{
    robot = robot_;
}

StatusCode PickUpWrench::execute(){
    /*
     * Change the arm position to slightly raised
     */
    //changeArmPosition.setup(ArmSlightlyRaised, 2.0f);
    //changeArmPosition.execute();

    /*
     * Move toward wrench
     */
    //logger->logMessage("Moving towards the wrench \r\n");
   // driveTilBump.setup(270, 50, RobotRight);
   // driveTilBump.execute();
    //driveForTime.setup(270, 50, 350);
    //driveForTime.execute();

    /*
     * Change the arm position to grab wrench
     */
    changeArmPosition.setup(ArmRight, 1.5f);
    changeArmPosition.execute();
    Sleep(.3f);
    //driveForTime.setup(180,40,400);
    //driveForTime.execute();
    //driveForTime.setup(0,40,200);
    //driveForTime.execute();
    /*
     * Raise arm to pickup wrench
     */
    changeArmPosition.setup(ArmUp, 0.1f);
    changeArmPosition.execute();

    /*
     * Back away from wrench stand
     */
   driveForTime.setup(90, 40, 200);
   driveForTime.execute();


    return Success;
}

