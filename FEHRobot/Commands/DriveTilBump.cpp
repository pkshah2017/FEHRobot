#include "DriveTilBump.h"
#include <FEHUtility.h>

DriveTilBump::DriveTilBump(Robot &robot_, int heading_, int power_, Direction direction_)
{
    robot = robot_;
    heading = heading_;
    power = power_;
    direction = direction_;
}

int DriveTilBump::setRobot(Robot &robot_){
    robot = robot_;
}

int DriveTilBump::changeHeading(int newHeading){
    heading = newHeading;
}

int DriveTilBump::changePower(int newPower){
    power = newPower;
}

int DriveTilBump::changeBumpDirection(Direction direction_){
    direction = direction_;
}

int DriveTilBump::initialize() {
    startTime = TimeNow();
    robot.updateSensorStates();

    return 0;
}

int DriveTilBump::run() {
    robot.drive(heading, power);
    robot.updateSensorStates();
    if(TimeNow() - startTime > TIMEOUT){
        return 1;
    }
    return 0;
}

int DriveTilBump::runFailureRecovery(int error){
    if(error == 1){
        robot.stop();
    }
    return error;
}

bool DriveTilBump::isFinished() {
    return !robot.getLimit(direction);
}

int DriveTilBump::completion(){
    robot.stop();

    return 0;
}

