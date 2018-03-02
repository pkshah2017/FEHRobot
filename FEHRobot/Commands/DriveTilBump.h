#ifndef DRIVETILBUMP
#define DRIVETILBUMP

#include "Command.h"
#include "Robot.h"
class DriveTilBump :
    public Command
{
public:
    DriveTilBump(Robot &robot_, int heading_, int power_, Direction direction_);

    int changeHeading(int newHeading);
    int changePower(int newPower);
    int changeBumpDirection(Direction direction_);
private:
    Robot robot;
    int heading;
    int power;
    float startTime;
    Direction direction;

    virtual int initialize();
    virtual int run();
    virtual bool isFinished();
    virtual int runFailureRecovery(int error);
    virtual int completion();
};


#endif
