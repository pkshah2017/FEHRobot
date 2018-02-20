#include "DriveTrain.h"
#include <math.h>
#include <FEHLCD.h>


#define MOTOR_VOLTAGE 7.2
#define PI 3.14159265358


DriveTrain::DriveTrain() :
    FLMotor(FEHMotor::Motor3, MOTOR_VOLTAGE),
    FRMotor(FEHMotor::Motor2, MOTOR_VOLTAGE),
    BLMotor(FEHMotor::Motor1, MOTOR_VOLTAGE),
    BRMotor(FEHMotor::Motor0, MOTOR_VOLTAGE),
    FrontLimit(FEHIO::P0_2),
    LeftLimit(FEHIO::P0_4),
    RightLimit(FEHIO::P0_6)
{
}

int DriveTrain::drive(int heading, int power) {

    float x = cos((45 - heading)*PI / 180.0);
    float y = sin((45 - heading)*PI / 180.0);
    LCD.WriteLine(x);
    LCD.WriteLine(y);

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

    return 0;
}