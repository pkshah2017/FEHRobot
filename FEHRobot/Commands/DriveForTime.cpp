#include "DriveForTime.h"
#include <FEHUtility.h>

DriveForTime::DriveForTime(Robot &robot_)
{
    robot = robot_;
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
