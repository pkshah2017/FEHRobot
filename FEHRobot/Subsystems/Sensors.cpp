#include "Sensors.h"

Sensors::Sensors()
    : FrontLimit(FEHIO::P0_2),
      LeftLimit(FEHIO::P0_4),
      RightLimit(FEHIO::P0_6)
{
}

bool Sensors::getFrontLimit() {
    return FrontLimit.Value();
}

bool Sensors::getLeftLimit() {
    return LeftLimit.Value();
}

bool Sensors::getRightLimit() {
    return RightLimit.Value();
}
