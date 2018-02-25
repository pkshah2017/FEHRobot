#include "Robot.h"
#include <FEHUtility.h>

Robot::Robot()
{
}

int Robot::updateSensorStates() {
    sensors.updateSensorStates();
}

bool Robot::getLimit(Direction direction) {
    bool result = false;
    switch(direction){
    case RobotFront:
        result = sensors.getFrontLimit();
        break;
    case RobotLeft:
        result = sensors.getLeftLimit();
        break;
    case RobotRight:
        result = sensors.getRightLimit();
        break;
    }

    return result;
}

float Robot::getCDSState(){
    return sensors.getCDSState();
}

int Robot::drive(int heading, int power) {
    driveTrain.drive(heading, power);

    return 0;
}

int Robot::stop() {
    driveTrain.stop();

    return 0;
}
