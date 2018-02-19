#pragma once
#include "FEHMotor.h"
#include "FEHIO.h"

class DriveTrain
{
private:
	int const MOTOR_VOLTAGE = 7.2;
	int const PI = 3.14159265358;

	FEHMotor::FEHMotorPort FLMotorPort = FEHMotor::FEHMotorPort::Motor0;
	FEHMotor::FEHMotorPort FRMotorPort = FEHMotor::FEHMotorPort::Motor1;
	FEHMotor::FEHMotorPort BLMotorPort = FEHMotor::FEHMotorPort::Motor2;
	FEHMotor::FEHMotorPort BRMotorPort = FEHMotor::FEHMotorPort::Motor3;

	FEHIO::FEHIOPin FrontLimitPort = FEHIO::FEHIOPin::P0_4;

	FEHMotor FLMotor = FEHMotor(FLMotorPort, MOTOR_VOLTAGE);
	FEHMotor FRMotor = FEHMotor(FRMotorPort, MOTOR_VOLTAGE);
	FEHMotor BLMotor = FEHMotor(BLMotorPort, MOTOR_VOLTAGE);
	FEHMotor BRMotor = FEHMotor(BRMotorPort, MOTOR_VOLTAGE);

	DigitalInputPin FrontLimit = DigitalInputPin(FrontLimitPort);
public:
	DriveTrain();

	int driveTilBump(int heading);
	int drive(int heading, int power);
	int stop();
};

