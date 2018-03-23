#include "WaitForTime.h"
#include <FEHUtility.h>

WaitForTime::WaitForTime(Robot *robot_, float sec_)
{
    constructor(robot_, sec_);
}

WaitForTime::WaitForTime(Robot *robot_, int ms)
{
    constructor(robot_, ms/1000.0);
}

StatusCode WaitForTime::constructor(Robot *robot_, float sec_){
    robot = robot_;
    StatusCode status = changeDriveTime(sec_);
    if(status != Success){
        LCD.Write("ERROR CODE: ");
        LCD.WriteLine((int)status);
        LCD.Write("Description: ");
        //LCD.WriteLine(errordesc[(int)status].message);
    }
}

StatusCode WaitForTime::changeDriveTime(int newTime){
    timeToWait = newTime/1000.0;
    return Success;
}

StatusCode WaitForTime::changeDriveTime(float newTime){
    timeToWait = newTime;
    return Success;
}

StatusCode WaitForTime::initialize() {
    startTime = TimeNow();

    return Success;
}

StatusCode WaitForTime::run() {
    return Success;
}

bool WaitForTime::isFinished() {
    return TimeNow() - startTime > timeToWait;
}

StatusCode WaitForTime::completion(){
    return Success;
}

const char * WaitForTime::getCommandName(){
    return "WaitForTime";
}
