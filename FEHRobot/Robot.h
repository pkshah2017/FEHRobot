#pragma once
#include "DriveTrain.h"
#include "Sensors.h"

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
};

