#include "DropOffWrench.h"
#include "FEHLCD.h"
#include <FEHUtility.h>

//All commands are initalized assuming the light will be red
//If light is blue, values are modified in failure recovery
DropOffWrench::DropOffWrench(Robot *robot_):
    driveForTime(robot_, 0, 50, 0),
    turnForTime(robot_, -25, 250),
    waitForTime(robot_, 2000),
    changeArmPosition(robot_, ArmRight, 1000),
    driveTilBump(robot_, 270, 50, RobotLeft),
    driveToLine(robot_, 35)
{
    robot = robot_;
}

StatusCode DropOffWrench::execute(){

    driveForTime.setup(0, 60, 50);
    driveForTime.execute();

    driveForTime.setup(90, 60, 200);
    driveForTime.execute();


    /*
     * Slightly lower arm
     */
    changeArmPosition.setup(ArmAngledRight, 50);
    changeArmPosition.execute();

    driveForTime.setup(260, 60, 300);
    driveForTime.execute();


    /*
     * Enter garage
     */
    driveForTime.setup(255, 60, 600);
    driveForTime.execute();

    /*
     * Lower Arm
     */
    changeArmPosition.setup(ArmRight, 50);
    changeArmPosition.execute();



    return Success;
}

