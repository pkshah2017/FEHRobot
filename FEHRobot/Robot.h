#ifndef ROBOT
#define ROBOT

#include "Subsystems/DriveTrain.h"
#include "Subsystems/Sensors.h"
#include "Subsystems/Arm.h"
#include "Subsystems/CrankArm.h"
#include "Subsystems/RPSLocations.h"

class Robot
{
private:
	DriveTrain driveTrain;
	Sensors sensors;
    Arm arm;
    CrankArm crankArm;
    RPSLocations rpsLocations;
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


    float getCurrentX();
    float getCurrentY();
    float getCurrentHeading();

    int turn(int power);
    int drive(int heading, int power);
    int driveAndTurn(int heading, int power, int turnSpeed);
    int stop();

    int setArmPosition(ArmPosition armPosition);
    int setCrankArmPosition(ArmPosition ArmPosition);

    void setLocation(LocationName locationName, float x, float y);
    void setLocation(LocationName locationName, Position position);

    float getLocationX(LocationName locationName, Course courseName);
    float getLocationY(LocationName locationName, Course courseName);
    Position getLocationPosition(LocationName locationName, Course courseName);
};

#endif
