#include <FEHIO.h>

class Sensors
{
private:
    DigitalInputPin FrontLimit;
    DigitalInputPin LeftLimit;
    DigitalInputPin RightLimit;

    bool frontLimitState;
    bool leftLimitState;
    bool rightLimitState;
public:
    Sensors();

    int updateSensorStates();

    bool getFrontLimit();
    bool getLeftLimit();
    bool getRightLimit();
};
