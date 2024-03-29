/*
 * This is the digital twin of the physical drive train. 
*/
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

    int driveAndTurn(int heading, int power, float turnSpeed);
    int turn(int power);
    int drive(int heading, int power);
    int stop();
};

#endif
