#ifndef CHANGEARMPOSITION
#define CHANGEARMPOSITION

#include "Command.h"
#include "Robot.h"
class ChangeArmPosition :
    public Command
{
public:
    ChangeArmPosition(Robot &robot_, ArmPosition armPosition_);
private:
    Robot robot;

    ArmPosition armPosition;

    virtual int initialize();
    virtual int run();
    virtual bool isFinished();
    virtual int completion();
};


#endif
