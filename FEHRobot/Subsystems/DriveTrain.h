#ifndef DRIVETRAIN
#define DRIVETRAIN

#include <FEHMotor.h>
#include <FEHIO.h>
#include "Constants.h"

class DriveTrain
{
private:
    FEHMotor FLMotor;
    FEHMotor FRMotor;
    FEHMotor BLMotor;
    FEHMotor BRMotor;
public:
    DriveTrain();

    int driveAndTurn(int heading, int power, int turnSpeed);
    int drive(int heading, int power);
    int stop();
};

#endif
