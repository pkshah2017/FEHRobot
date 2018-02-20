#include "Sensors.h"

Sensors::Sensors()
    : FrontLimit(FEHIO::P0_2),
    LeftLimit(FEHIO::P0_4),
    RightLimit(FEHIO::P0_6)
{
}

int Sensors::updateSensorStates() {
    frontLimitState = FrontLimit.Value();
    leftLimitState = LeftLimit.Value();
    rightLimitState = RightLimit.Value();
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
