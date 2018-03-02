#include "LineFollowForTime.h"
#include <FEHUtility.h>

LineFollowForTime::LineFollowForTime(Robot &robot_, int power_, float sec_)
{
    constructor(robot_, power_, sec_);
}

LineFollowForTime::LineFollowForTime(Robot &robot_, int power_, int ms)
{
    constructor(robot_, power_, ms/1000.0);
}

int LineFollowForTime::constructor(Robot &robot_, int power_, float sec_){
    robot = robot_;
    power = power_;
    timeToWait = sec_;
}

int LineFollowForTime::setRobot(Robot &robot_){
    robot = robot_;
}

int LineFollowForTime::changePower(int newPower){
    power = newPower;
}

int LineFollowForTime::changeDriveTime(int newTime){
    timeToWait = newTime/1000.0;
}

int LineFollowForTime::changeDriveTime(float newTime){
    timeToWait = newTime;
}

int LineFollowForTime::updateLineFollowerState(float leftThreshold, float centerThreshold, float rightTheshold){
    robot.updateSensorStates();

    float left = robot.getOpto(LeftOpto);
    float center = robot.getOpto(CenterOpto);
    float right = robot.getOpto(RightOpto);

    //   > is black (on)     < is white (off)
    if (right < rightTheshold && center > centerThreshold && left < leftThreshold) {
        lineFollowStatus = OFF_ON_OFF; // update a new state
    }
    else if (right < rightTheshold && center > centerThreshold && left > leftThreshold) {
        lineFollowStatus = OFF_ON_ON; // update a new state
    }
    else if (right < rightTheshold &&  center < centerThreshold && left > leftThreshold) {
        lineFollowStatus = OFF_OFF_ON; // update a new state
    }
    else if (right > rightTheshold && center > centerThreshold && left < leftThreshold) {
        lineFollowStatus = ON_ON_OFF; // update a new state
    }
    else if (right > rightTheshold && center <centerThreshold && left < leftThreshold) {
        lineFollowStatus = ON_OFF_OFF; // update a new state
    }
    else
    {
        lineFollowStatus = OFF_OFF_OFF;
    }
    return 0;
}

int LineFollowForTime::initialize() {
    startTime = TimeNow();

    return 0;
}

int LineFollowForTime::run() {
    updateLineFollowerState(99, 99, 99);

    switch(lineFollowStatus){
    case OFF_ON_OFF:
        robot.drive(0, power);
        break;
    case ON_ON_OFF:
        robot.drive(45, power);
        break;
    case ON_OFF_OFF:
        robot.drive(90, power);
        break;
    case OFF_ON_ON:
        robot.drive(315, power);
        break;
    case OFF_OFF_ON:
        robot.drive(270, power);
        break;
    case OFF_OFF_OFF:
            robot.stop();
        break;
    }

    return 0;
}

bool LineFollowForTime::isFinished() {
    return TimeNow() - startTime > timeToWait;
}

int LineFollowForTime::completion(){
    robot.stop();

    return 0;
}
