#include "DriveForTime.h"
#include <FEHUtility.h>

DriveForTime::DriveForTime(Robot &robot_, int heading_, int power_, float sec_)
{
    constructor(robot_, heading_, power_, sec_);
}

DriveForTime::DriveForTime(Robot &robot_, int heading_, int power_, int ms)
{
     constructor(robot_, heading_, power_, ms/1000.0);
}

int DriveForTime::constructor(Robot &robot_, int heading_, int power_, float sec_){
    robot = robot_;
    heading = heading_;
    power = power_;
    timeToWait = sec_;
}

int DriveForTime::initialize() {
    startTime = TimeNow();
}

int DriveForTime::run() {
}

bool DriveForTime::isFinished() {
    return TimeNow() - startTime > timeToWait;
}
