#include "DriveTilBump.h"
#include <FEHUtility.h>

#define TIMEOUT 5.0

DriveTilBump::DriveTilBump(Robot &robot_, int heading_, int power_, Robot::Direction direction_)
{
    robot = robot_;
    heading = heading_;
    power = power_;
    direction = direction_;
}

int DriveTilBump::initialize() {
    startTime = TimeNow();
    robot.updateSensorStates();
}

int DriveTilBump::run() {
    robot.drive(heading, power);
    robot.updateSensorStates();
    if(TimeNow() - startTime > TIMEOUT){
        return 1;
    }
}

int DriveTilBump::runFailureRecovery(int error){
    if(error == 1){
        robot.stop();
    }
    return error;
}

bool DriveTilBump::isFinished() {
    return robot.getLimit(direction);
}
