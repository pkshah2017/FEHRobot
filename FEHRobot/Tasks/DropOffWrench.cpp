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
    /*
     * Slightly lower arm
     */
    changeArmPosition.setup(ArmAngledRight, 500);
    changeArmPosition.execute();

    /*
     * Enter garage
     */
    driveForTime.setup(270, 60, 1200);
    driveForTime.execute();

    /*
     * Lower Arm
     */
    changeArmPosition.setup(ArmRight, 1500);
    changeArmPosition.execute();



    return Success;
}

