#include "DriveTilBump.h"



DriveTilBump::DriveTilBump(Robot &robot_, int heading_, int power_, Robot::Direction direction_)
{
    robot = robot_;
    heading = heading_;
    power = power_;
    direction = direction_;
}

int DriveTilBump::initialize() {
    robot.updateSensorStates();
}

int DriveTilBump::run() {
    robot.drive(heading, power);
    robot.updateSensorStates();
}

bool DriveTilBump::isFinished() {
    return robot.getLimit(direction);
}
