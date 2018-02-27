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

float Robot::getOpto(OptoSelection optoSelection) {
    float result = -1;
    switch(optoSelection){
    case LeftOpto:
        result = sensors.getLeftOpto();
        break;
    case CenterOpto:
        result = sensors.getCenterOpto();
        break;
    case RightOpto:
        result = sensors.getRightOpto();
        break;
    }

    return result;
}

float Robot::getCDSState(){
    return sensors.getCDSState();
}

float Robot::getX(){
    return sensors.robotX();
}

float Robot::getY(){
    return sensors.robotY();
}

float Robot::getHeading(){
    return sensors.robotHeading();
}

int Robot::getFuelType(){
    return sensors.fuelType();
}

int Robot::getDeadzoneStatus(){
    return sensors.isDeadzoneActive();
}

int Robot::turn(int power) {
    driveTrain.turn(power);

    return 0;
}

int Robot::drive(int heading, int power) {
    driveTrain.drive(heading, power);

    return 0;
}

int Robot::stop() {
    driveTrain.stop();

    return 0;
}
