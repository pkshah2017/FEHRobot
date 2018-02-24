#ifndef ROBOT
#define ROBOT

#include "Subsystems/DriveTrain.h"
#include "Subsystems/Sensors.h"

typedef enum {
    Front, Left, Right
} Direction;

class Robot
{
private:
	DriveTrain driveTrain;
	Sensors sensors;
public:

	Robot();
	int driveTilFrontBump(int heading, int power);
	int driveTilLeftBump(int heading, int power);
	int driveTilRightBump(int heading, int power);
	int driveForTime(int heading, int power, int ms);
    int driveForTime(int heading, int power, float sec);
    int waitTilStartLight();

    int updateSensorStates();

    bool getLimit(Direction direction);

    int drive(int heading, int power);
    int stop();
};

#endif
