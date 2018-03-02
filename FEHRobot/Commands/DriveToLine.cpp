#include "DriveToLine.h"
#include <FEHUtility.h>

DriveToLine::DriveToLine(Robot &robot_, int power_)
{
    robot = robot_;
    power = power_;
}

int DriveToLine::initialize() {
    int status = updateLineFollowerState(99, 99, 99);

    return status;
}

int DriveToLine::run() {
    int status = updateLineFollowerState(99, 99, 99);

    switch(lineFollowStatus){
    case OFF_ON_OFF:
        //Should never happen
        return 6;
        break;
    case ON_ON_OFF:
        robot.turn(-25);
        break;
    case ON_OFF_OFF:
        robot.turn(-25);
        break;
    case OFF_ON_ON:
        robot.turn(25);
        break;
    case OFF_OFF_ON:
        robot.turn(25);
        break;
    case OFF_OFF_OFF:
        robot.drive(0, power);
        break;
    }

    return status;
}

bool DriveToLine::isFinished() {
    return lineFollowStatus == ON_ON_ON;
}

int DriveToLine::completion(){
    robot.stop();

    return 0;
}


int DriveToLine::updateLineFollowerState(float leftThreshold, float centerThreshold, float rightTheshold){
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
