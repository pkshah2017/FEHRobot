#include "TurnForTime.h"
#include <FEHUtility.h>

//Positive Power is to the right

TurnForTime::TurnForTime(Robot &robot_, int power_, float sec_)
{
    constructor(robot_, power_, sec_);
}

TurnForTime::TurnForTime(Robot &robot_, int power_, int ms)
{
    constructor(robot_, power_, ms/1000.0);
}

int TurnForTime::constructor(Robot &robot_, int power_, float sec_){
    robot = robot_;
    power = power_;
    timeToWait = sec_;
}

int TurnForTime::changePower(int newPower){
    power = newPower;
}

int TurnForTime::changeDriveTime(int newTime){
    timeToWait = newTime/1000.0;
}

int TurnForTime::changeDriveTime(float newTime){
    timeToWait = newTime;
}

int TurnForTime::initialize() {
    startTime = TimeNow();

    return 0;
}

int TurnForTime::run() {
    robot.turn(power);

    return 0;
}

bool TurnForTime::isFinished() {
    return TimeNow() - startTime > timeToWait;
}

int TurnForTime::completion(){
    robot.stop();

    return 0;
}
