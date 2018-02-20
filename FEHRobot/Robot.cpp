#include "Robot.h"
#include "FEHUtility.h"

Robot::Robot()
{
}


int Robot::driveTilFrontBump(int heading, int power) {
	driveTrain.drive(heading, power);
	while (sensors.getFrontLimit());
	driveTrain.stop();
	return 0;
}

int Robot::driveTilLeftBump(int heading, int power) {
	driveTrain.drive(heading, power);
	while (sensors.getLeftLimit());
	driveTrain.stop();
	return 0;
}

int Robot::driveTilRightBump(int heading, int power) {
	driveTrain.drive(heading, power);
	while (sensors.getRightLimit());
	driveTrain.stop();
	return 0;
}


int Robot::driveForTime(int heading, int power, int ms) {
	driveTrain.drive(heading, 50);
	Sleep(ms);
	driveTrain.stop();
}