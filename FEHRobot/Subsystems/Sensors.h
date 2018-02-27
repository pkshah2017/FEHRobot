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
    AnalogInputPin leftOpto;
    AnalogInputPin centerOpto;
    AnalogInputPin rightOpto;

    bool frontLimitState;
    bool leftLimitState;
    bool rightLimitState;
    float cdsState;
    float leftOptoState;
    float centerOptoState;
    float rightOptoState;
public:
    Sensors();

    int updateSensorStates();

    bool getFrontLimit();
    bool getLeftLimit();
    bool getRightLimit();
    float getCDSState();
    float getLeftOpto();
    float getCenterOpto();
    float getRightOpto();

    int fuelType();
    int isDeadzoneActive();
    float robotX();
    float robotY();
    float robotHeading();

};

#endif
