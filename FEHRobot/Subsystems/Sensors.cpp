#include "Sensors.h"
#include <FEHRPS.h>

Sensors::Sensors()
    : FrontLimit(FEHIO::P0_2),
      LeftLimit(FEHIO::P0_6),
      RightLimit(FEHIO::P0_4),
      cdsCell(FEHIO::P0_0),
      leftOpto(FEHIO::P1_4),
      centerOpto(FEHIO::P1_2),
      rightOpto(FEHIO::P1_0 )
{
    updateSensorStates();
}

int Sensors::updateSensorStates() {
    frontLimitState = FrontLimit.Value();
    leftLimitState = LeftLimit.Value();
    rightLimitState = RightLimit.Value();
    cdsState = cdsCell.Value();
    leftOptoState = leftOpto.Value();
    centerOptoState = centerOpto.Value();
    rightOptoState = rightOpto.Value();
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

float Sensors::getLeftOpto() {
    return leftOptoState;
}

float Sensors::getCenterOpto() {
    return centerOptoState;
}

float Sensors::getRightOpto() {
    return rightOptoState;
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
