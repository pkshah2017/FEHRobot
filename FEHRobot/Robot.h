#ifndef ROBOT
#define ROBOT

#include "Subsystems/DriveTrain.h"
#include "Subsystems/Sensors.h"
#include "Subsystems/Arm.h"
#include "Subsystems/CrankArm.h"

class Robot
{
private:
	DriveTrain driveTrain;
	Sensors sensors;
    Arm arm;
    CrankArm crankArm;
public:

    Robot();

    int updateSensorStates();
    int updateRPSStates();

    bool getLimit(Direction direction);
    float getCDSState();
    float getOpto(OptoSelection optoSelection);
    float getX();
    float getY();
    float getHeading();
    int getFuelType();
    int getDeadzoneStatus();

    int turn(int power);
    int drive(int heading, int power);
    int driveAndTurn(int heading, int power, int turnSpeed);
    int stop();

    int setArmPosition(ArmPosition armPosition);
    int setCrankArmPosition(ArmPosition ArmPosition);
};

#endif
