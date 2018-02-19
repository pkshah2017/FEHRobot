#include "Robot.h"



Robot::Robot()
{
}


int Robot::driveTilBump(int heading) {
	driveTrain.driveTilBump(heading);

	return 0;
}