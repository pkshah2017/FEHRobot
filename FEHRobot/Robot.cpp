#include "Robot.h"
#include <FEHUtility.h>

Robot::Robot()
{
}


int Robot::driveTilFrontBump(int heading, int power) {
    driveTrain.drive(heading, power);
    while (sensors.getFrontLimit()){
        Sleep(20);
        sensors.updateSensorStates();
    }
    driveTrain.stop();
    return 0;
}

int Robot::driveTilLeftBump(int heading, int power) {
    driveTrain.drive(heading, power);
    while (sensors.getLeftLimit()){
        Sleep(20);
        sensors.updateSensorStates();
    }
    driveTrain.stop();
    return 0;
}

int Robot::driveTilRightBump(int heading, int power) {
    driveTrain.drive(heading, power);
    while (sensors.getRightLimit()){
        Sleep(20);
        sensors.updateSensorStates();
    }
    driveTrain.stop();
    return 0;
}


int Robot::driveForTime(int heading, int power, int ms) {
    driveTrain.drive(heading, 50);
    Sleep(ms);
    driveTrain.stop();
}
