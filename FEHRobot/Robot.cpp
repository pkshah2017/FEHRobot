#include "Robot.h"
#include <FEHUtility.h>

#define REFRESH_RATE 20

Robot::Robot()
{
}


int Robot::driveTilFrontBump(int heading, int power) {
    driveTrain.drive(heading, power);
    while (sensors.getFrontLimit()){
        Sleep(REFRESH_RATE);
        sensors.updateSensorStates();
    }
    driveTrain.stop();
    return 0;
}

int Robot::driveTilLeftBump(int heading, int power) {
    driveTrain.drive(heading, power);
    while (sensors.getLeftLimit()){
        Sleep(REFRESH_RATE);
        sensors.updateSensorStates();
    }
    driveTrain.stop();
    return 0;
}

int Robot::driveTilRightBump(int heading, int power) {
    driveTrain.drive(heading, power);
    while (sensors.getRightLimit()){
        Sleep(REFRESH_RATE);
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

int Robot::driveForTime(int heading, int power, float sec) {
    driveForTime(heading, power, sec*1000);
}

int Robot::waitTilStartLight(){
    do{
        Sleep(REFRESH_RATE);
        sensors.updateSensorStates();
    } while(sensors.getCDSState() < 1.2);
}
