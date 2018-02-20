#include <FEHIO.h>

class Sensors
{
private:
    DigitalInputPin FrontLimit;
    DigitalInputPin LeftLimit;
    DigitalInputPin RightLimit;
public:
    Sensors();
    bool getFrontLimit();
    bool getLeftLimit();
    bool getRightLimit();
};

