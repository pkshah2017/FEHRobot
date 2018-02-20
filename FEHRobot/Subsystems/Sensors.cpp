#include "Sensors.h"

Sensors::Sensors()
    : FrontLimit(FEHIO::P0_2),
      LeftLimit(FEHIO::P0_4),
      RightLimit(FEHIO::P0_6),
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
