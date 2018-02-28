#include "MoveArmButtons.h"
#include <FEHUtility.h>
#include <FEHLCD.h>

MoveArmButtons::MoveArmButtons(Robot &robot_)
{
    robot = robot_;
    timeToWait = MOVE_ARM_WAIT;
}

int MoveArmButtons::initialize() {
    robot.updateSensorStates();

    LCD.WriteRC("CDS VALUE", 2 , 1);
    LCD.WriteRC(robot.getCDSState(), 2 , 1);

    startTime = TimeNow();

    int status = 5;
    if(robot.getCDSState() < .85){
        robot.setArmPosition(ArmRight);
        status = 4;
    } else if(robot.getCDSState() < 1.8){
        robot.setArmPosition(ArmLeft);
        status = 3;
    }

    return status;
}

int MoveArmButtons::run() {
    return 0;
}

bool MoveArmButtons::isFinished() {
    return TimeNow() - startTime > timeToWait;
}

int MoveArmButtons::completion(){
    return 0;
}

