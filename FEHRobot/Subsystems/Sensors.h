#ifndef SENSORS
#define SENSORS

#include <FEHIO.h>
#include "Constants.h"

class Sensors
{
private:
    DigitalInputPin FrontLimit;
    DigitalInputPin LeftLimit;
    DigitalInputPin RightLimit;

    AnalogInputPin cdsCell;

    bool frontLimitState;
    bool leftLimitState;
    bool rightLimitState;
    float cdsState;
public:
    Sensors();

    int updateSensorStates();

    bool getFrontLimit();
    bool getLeftLimit();
    bool getRightLimit();
    float getCDSState();
};

#endif
