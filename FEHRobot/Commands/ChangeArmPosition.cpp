#include "ChangeArmPosition.h"
#include <FEHUtility.h>
#include <FEHLCD.h>

ChangeArmPosition::ChangeArmPosition(Robot &robot_, ArmPosition armPosition_)
{
    robot = robot_;
    armPosition = armPosition_;
}

int ChangeArmPosition::initialize() {
    robot.setArmPosition(armPosition);

    return 0;
}

int ChangeArmPosition::run() {
    return 0;
}

bool ChangeArmPosition::isFinished() {
    return true;
}

int ChangeArmPosition::completion(){
    return 0;
}

