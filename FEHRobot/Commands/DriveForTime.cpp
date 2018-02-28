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

    return 0;
}

int DriveForTime::run() {
    robot.drive(heading, power);

    return 0;
}

bool DriveForTime::isFinished() {
    return TimeNow() - startTime > timeToWait;
}

int DriveForTime::completion(){
    robot.stop();

    return 0;
}

int DriveForTime::changeHeading(int newHeading){
    heading = newHeading;
}

int DriveForTime::changeDriveTime(int newTime){
    timeToWait = newTime/1000.0;
}

int DriveForTime::changeDriveTime(float newTime){
    timeToWait = newTime;
}
