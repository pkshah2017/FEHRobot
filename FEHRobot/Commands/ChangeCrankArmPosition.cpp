#include "ChangeCrankArmPosition.h"
#include <FEHUtility.h>
#include <FEHLCD.h>

ChangeCrankArmPosition::ChangeCrankArmPosition(Robot *robot_)
{
    constructor(robot_, ArmUp, 0.0);
}

ChangeCrankArmPosition::ChangeCrankArmPosition(Robot *robot_, ArmPosition armPosition_, float sec)
{
    constructor(robot_, armPosition_, sec);
}

ChangeCrankArmPosition::ChangeCrankArmPosition(Robot *robot_, ArmPosition armPosition_, int ms)
{
    constructor(robot_, armPosition_, ms/1000.0);
}

StatusCode ChangeCrankArmPosition::constructor(Robot *robot_, ArmPosition armPosition_, float sec_){
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

StatusCode ChangeCrankArmPosition::setup(ArmPosition armPosition_, float sec_){
    StatusCode status = selectArmPosition(armPosition_);
    if(status == Success) {
        status = selectWaitTime(sec_);
    }
    return Success;
}

StatusCode ChangeCrankArmPosition::selectArmPosition(ArmPosition armPosition_){
    armPosition = armPosition_;
    return Success;
}

StatusCode ChangeCrankArmPosition::selectWaitTime(int ms){
    timeToWait = ms/1000.0;
    return Success;
}

StatusCode ChangeCrankArmPosition::selectWaitTime(float sec){
    timeToWait = sec;
    return Success;
}

StatusCode ChangeCrankArmPosition::initialize() {
    (*robot).setCrankArmPosition(armPosition);
    startTime = TimeNow();

    return Success;
}

StatusCode ChangeCrankArmPosition::run() {
    return Success;
}

bool ChangeCrankArmPosition::isFinished() {
    return TimeNow() - startTime > timeToWait;
}

StatusCode ChangeCrankArmPosition::completion(){
    return Success;
}

