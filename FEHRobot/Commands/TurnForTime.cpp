#include "Logger.h"
#include "TurnForTime.h"
#include <FEHUtility.h>

//Positive Power is to the right

TurnForTime::TurnForTime(Robot *robot_, int power_, float sec_)
{
    constructor(robot_, power_, sec_);
}

TurnForTime::TurnForTime(Robot *robot_, int power_, int ms)
{
    constructor(robot_, power_, ms/1000.0f);
}

StatusCode TurnForTime::constructor(Robot *robot_, int power_, float sec_){
    robot = robot_;
    StatusCode status = setup(power_, sec_);
    if(status != Success){
        logger->logError(status);
    }
}

StatusCode TurnForTime::setup(int newPower, int newTime){
    return setup(newPower, newTime/1000.0f);
}

StatusCode TurnForTime::setup(int newPower, float newTime){
    StatusCode status = changePower(newPower);
    if(status == Success){
        status = changeDriveTime(newTime);
    }
    return status;
}

StatusCode TurnForTime::changePower(int newPower){
    power = newPower;
    return Success;
}

StatusCode TurnForTime::changeDriveTime(int newTime){
    timeToWait = newTime/1000.0;
    return Success;
}

StatusCode TurnForTime::changeDriveTime(float newTime){
    timeToWait = newTime;
    return Success;
}

StatusCode TurnForTime::initialize() {
    startTime = TimeNow();

    return Success;
}

StatusCode TurnForTime::run() {
    (*robot).turn(power);

    return Success;
}

bool TurnForTime::isFinished() {
    return TimeNow() - startTime > timeToWait;
}

StatusCode TurnForTime::completion(){
    (*robot).stop();

    return Success;
}

const char * TurnForTime::getCommandName(){
    return "TurnForTime";
}
