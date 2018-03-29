#include "ChangeArmPosition.h"
#include <FEHUtility.h>
#include <FEHLCD.h>

ChangeArmPosition::ChangeArmPosition(Robot *robot_)
{
    constructor(robot_, ArmUp, 0.0);
}

ChangeArmPosition::ChangeArmPosition(Robot *robot_, ArmPosition armPosition_, float sec)
{
    constructor(robot_, armPosition_, sec);
}

ChangeArmPosition::ChangeArmPosition(Robot *robot_, ArmPosition armPosition_, int ms)
{
    constructor(robot_, armPosition_, ms/1000.0f);
}

StatusCode ChangeArmPosition::constructor(Robot *robot_, ArmPosition armPosition_, float sec_){
    robot = robot_;
    StatusCode status = setup(armPosition_, sec_);
    if(status != Success){
        LCD.Write("ERROR CODE: ");
        LCD.WriteLine((int)status);
        LCD.Write("Description: ");
        //LCD.WriteLine(errordesc[(int)status].message);
    }
    return status;
}

StatusCode ChangeArmPosition::setup(ArmPosition armPosition_, int ms){
    StatusCode status = selectArmPosition(armPosition_);
    if(status == Success) {
        status = selectWaitTime(ms/1000.0f);
    }
    return Success;
}

StatusCode ChangeArmPosition::setup(ArmPosition armPosition_, float sec_){
    StatusCode status = selectArmPosition(armPosition_);
    if(status == Success) {
        status = selectWaitTime(sec_);
    }
    return Success;
}

StatusCode ChangeArmPosition::selectArmPosition(ArmPosition armPosition_){
    armPosition = armPosition_;
    return Success;
}

StatusCode ChangeArmPosition::selectWaitTime(int ms){
    timeToWait = ms/1000.0f;
    return Success;
}

StatusCode ChangeArmPosition::selectWaitTime(float sec){
    timeToWait = sec;
    return Success;
}

StatusCode ChangeArmPosition::initialize() {
    (*robot).setArmPosition(armPosition);
    startTime = TimeNow();

    return Success;
}

StatusCode ChangeArmPosition::run() {
    return Success;
}

bool ChangeArmPosition::isFinished() {
    return TimeNow() - startTime > timeToWait;
}

StatusCode ChangeArmPosition::completion(){
    return Success;
}

const char * ChangeArmPosition::getCommandName(){
    return "ChangeArmPosition";
}

