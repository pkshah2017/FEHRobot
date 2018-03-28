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
    changeArmPosition.setup(ArmSlightlyRaised, 2.0f);
    changeArmPosition.execute();

    /*
     * Move toward wrench
     */
    driveTilBump.setup(270, 50, RobotRight);
    driveTilBump.execute();
   // driveForTime.setup(270, 50, 250);
   // driveForTime.execute();

    /*
     * Change the arm position to grab wrench
     */
    changeArmPosition.setup(ArmRight, 0.75f);
    changeArmPosition.execute();

    /*
     * Raise arm to pickup wrench
     */
    changeArmPosition.setup(ArmUp, 2.0f);
    changeArmPosition.execute();

    /*
     * Back away from wrench stand
     */
    driveForTime.setup(90, 50, 500);
    driveForTime.execute();


    return Success;
}

