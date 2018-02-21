#include "Command.h"
#include "Robot.h"
class DriveTilBump :
    public Command
{
public:
    DriveTilBump(Robot &robot_, int heading_, int power_, Robot::Direction direction_);
private:
    Robot robot;
    int heading;
    int power;
    float startTime;
    Robot::Direction direction;

    virtual int initialize();
    virtual int run();
    virtual bool isFinished();
    virtual int runFailureRecovery(int error);
};

