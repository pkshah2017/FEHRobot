#include "DriveForTime.h"
#include <FEHUtility.h>

DriveForTime::DriveForTime(Robot &robot_, int heading_, int power_, float sec_)
{
    robot = robot_;
    setup(heading_, power_, sec_);
}

DriveForTime::DriveForTime(Robot &robot_, int heading_, int power_, int ms)
{
    robot = robot_;
    setup(heading_, power_, ms);
}

void DriveForTime::setup(int newHeading,int newPower, int newTime){
    heading = newHeading;
    power = newPower;
    timeToWait =newTime/1000.0;
}
void DriveForTime::setup(int newHeading,int newPower, float newTime){
    heading = newHeading;
    power = newPower;
    timeToWait =newTime;
}

int DriveForTime::changeHeading(int newHeading){
    heading = newHeading;
}

int DriveForTime::changePower(int newPower){
    power = newPower;
}

int DriveForTime::changeDriveTime(int newTime){
    timeToWait = newTime/1000.0;
}

int DriveForTime::changeDriveTime(float newTime){
    timeToWait = newTime;
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
