#include "Sensors.h"
#include <FEHRPS.h>

Sensors::Sensors()
    : FrontLimit(FEHIO::P0_2),
      LeftLimit(FEHIO::P0_6),
      RightLimit(FEHIO::P0_4),
      cdsCell(FEHIO::P0_0)
{
    updateSensorStates();
}

int Sensors::updateSensorStates() {
    frontLimitState = FrontLimit.Value();
    leftLimitState = LeftLimit.Value();
    rightLimitState = RightLimit.Value();
    cdsState = cdsCell.Value();
}

bool Sensors::getFrontLimit() {
    return frontLimitState;
}

bool Sensors::getLeftLimit() {
    return leftLimitState;
}

bool Sensors::getRightLimit() {
    return rightLimitState;
}

float Sensors::getCDSState() {
    return cdsState;
}

int Sensors::fuelType(){
    //return RPS.FuelType();
    return 0;
}

int Sensors::isDeadzoneActive(){
    //return RPS.IsDeadzoneActive();
    return 0;
}

float Sensors::robotX(){
    return RPS.X();
}

float Sensors::robotY(){
    return RPS.Y();
}

float Sensors::robotHeading(){
    return RPS.Heading();
}
