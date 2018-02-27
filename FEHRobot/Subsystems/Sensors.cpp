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
    return RPS.FuelType();
}

int Sensors::isDeadzoneActive(){
    return RPS.IsDeadzoneActive();
}

int Sensors::robotX(){
    return RPS.X();
}

int Sensors::robotY(){
    return RPS.Y();
}

int Sensors::robotHeading(){
    return RPS.Heading();
}
