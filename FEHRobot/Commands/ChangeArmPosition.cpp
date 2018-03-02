#include "ChangeArmPosition.h"
#include <FEHUtility.h>
#include <FEHLCD.h>

ChangeArmPosition::ChangeArmPosition(Robot &robot_, ArmPosition armPosition_, float sec)
{
    constructor(robot_, armPosition_, sec);
}

ChangeArmPosition::ChangeArmPosition(Robot &robot_, ArmPosition armPosition_, int ms)
{
    constructor(robot_, armPosition_, ms/1000.0);
}

int ChangeArmPosition::constructor(Robot &robot_, ArmPosition armPosition_, float sec_){
    robot = robot_;
    armPosition = armPosition_;
    timeToWait = sec_;
}

int ChangeArmPosition::setRobot(Robot &robot_){
    robot = robot_;
}

int ChangeArmPosition::selectArmPosition(ArmPosition armPosition_){
    armPosition = armPosition_;
}

int ChangeArmPosition::selectWaitTime(int ms){
    timeToWait = ms/1000.0;
}

int ChangeArmPosition::selectWaitTime(float sec){
    timeToWait = sec;
}

int ChangeArmPosition::initialize() {
    robot.setArmPosition(armPosition);
    startTime = TimeNow();

    return 0;
}

int ChangeArmPosition::run() {
    return 0;
}

bool ChangeArmPosition::isFinished() {
    return TimeNow() - startTime > timeToWait;
}

int ChangeArmPosition::completion(){
    return 0;
}

