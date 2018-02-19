#pragma once
#include "DriveTrain.h"
class Robot
{
private:
	DriveTrain driveTrain;
public:
	Robot();
	int driveTilBump(int heading);
};

