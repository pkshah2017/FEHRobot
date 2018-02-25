#ifndef ROBOT
#define ROBOT

#include "Subsystems/DriveTrain.h"
#include "Subsystems/Sensors.h"

class Robot
{
private:
	DriveTrain driveTrain;
	Sensors sensors;
public:

    Robot();

    int updateSensorStates();

    bool getLimit(Direction direction);
    float getCDSState();

    int drive(int heading, int power);
    int stop();
};

#endif
