#include "DriveTrain.h"
#include <math.h>



DriveTrain::DriveTrain()
{
}

int DriveTrain::driveTilBump() {
	drive(0, 50);
	while (!FrontLimit.Value());
	stop();
}

int DriveTrain::drive(int heading, int power) {
	
	int x = cos((45 - heading)*PI / 180.0);
	int y = sin((45 - heading)*PI / 180.0);
	
	FLMotor.SetPercent(x*power);
	FRMotor.SetPercent(-y*power);
	BLMotor.SetPercent(-x*power);
	BRMotor.SetPercent(y*power);

	return 0;
}

int DriveTrain::stop() {
	FLMotor.Stop();
	FRMotor.Stop();
	BLMotor.Stop();
	BRMotor.Stop();
}