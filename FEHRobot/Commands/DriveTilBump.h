#ifndef DRIVETILBUMP
#define DRIVETILBUMP

#include "Command.h"
#include "Robot.h"
class DriveTilBump :
    public Command
{
public:
    DriveTilBump(Robot *robot_, int heading_, int power_, Direction direction_);

    StatusCode setup(int newHeading, int newPower,Direction newDirection);

    StatusCode changeHeading(int newHeading);
    StatusCode changePower(int newPower);
    StatusCode changeBumpDirection(Direction direction_);

    virtual const char* getCommandName();
private:
    Robot *robot;
    int heading;
    int power;
    float startTime;
    Direction direction;

    virtual StatusCode initialize();
    virtual StatusCode run();
    virtual bool isFinished();
    virtual StatusCode initializeFailureRecovery(StatusCode error);
    virtual StatusCode runFailureRecovery(StatusCode error);
    virtual StatusCode completion();
};


#endif
