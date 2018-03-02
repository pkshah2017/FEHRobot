#include "WaitForTime.h"
#include <FEHUtility.h>

WaitForTime::WaitForTime(Robot &robot_, float sec_)
{
    constructor(robot_, sec_);
}

WaitForTime::WaitForTime(Robot &robot_, int ms)
{
    constructor(robot_, ms/1000.0);
}

int WaitForTime::setRobot(Robot &robot_){
    robot = robot_;
}

int WaitForTime::constructor(Robot &robot_, float sec_){
    robot = robot_;
    timeToWait = sec_;
}

int WaitForTime::changeDriveTime(int newTime){
    timeToWait = newTime/1000.0;
}

int WaitForTime::changeDriveTime(float newTime){
    timeToWait = newTime;
}

int WaitForTime::initialize() {
    startTime = TimeNow();

    return 0;
}

int WaitForTime::run() {

    return 0;
}

bool WaitForTime::isFinished() {
    return TimeNow() - startTime > timeToWait;
}

int WaitForTime::completion(){
    robot.stop();

    return 0;
}
