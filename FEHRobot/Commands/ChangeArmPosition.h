#ifndef CHANGEARMPOSITION
#define CHANGEARMPOSITION

#include "Command.h"
#include "Robot.h"
class ChangeArmPosition :
    public Command
{
public:
    ChangeArmPosition(Robot &robot_, ArmPosition armPosition_, int ms);
    ChangeArmPosition(Robot &robot_, ArmPosition armPosition_, float sec);
private:
    Robot robot;

    int startTime;
    int timeToWait;
    ArmPosition armPosition;

    int constructor(Robot &robot_, ArmPosition armPosition_, float sec);

    virtual int initialize();
    virtual int run();
    virtual bool isFinished();
    virtual int completion();
};


#endif
