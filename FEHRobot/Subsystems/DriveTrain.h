#include <FEHMotor.h>
#include <FEHIO.h>

class DriveTrain
{
private:
    FEHMotor FLMotor;
    FEHMotor FRMotor;
    FEHMotor BLMotor;
    FEHMotor BRMotor;

    DigitalInputPin FrontLimit;
    DigitalInputPin LeftLimit;
    DigitalInputPin RightLimit;
public:
    DriveTrain();

    int driveForTime(int heading, int ms);
    int drive(int heading, int power);
    int stop();
};
