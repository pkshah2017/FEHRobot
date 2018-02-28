#ifndef ROBOT
#define ROBOT

#include "Subsystems/DriveTrain.h"
#include "Subsystems/Sensors.h"
#include "Subsystems/Arm.h"

class Robot
{
private:
	DriveTrain driveTrain;
	Sensors sensors;
    Arm arm;
public:

    Robot();

    int updateSensorStates();

    bool getLimit(Direction direction);
    float getCDSState();
    float getOpto(OptoSelection optoSelection);
    float getX();
    float getY();
    float getHeading();
    int getFuelType();
    int getDeadzoneStatus();

    int turn(int power);
    int drive(int heading, int power);
    int stop();

    int setArmPosition(ArmPosition armPosition);
};

#endif
