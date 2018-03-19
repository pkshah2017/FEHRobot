#ifndef CHANGEARMPOSITION
#define CHANGEARMPOSITION

#include "Command.h"
#include "Robot.h"
class ChangeArmPosition :
        public Command
{
public:
    ChangeArmPosition(Robot &robot_);
    ChangeArmPosition(Robot &robot_, ArmPosition armPosition_, int ms);
    ChangeArmPosition(Robot &robot_, ArmPosition armPosition_, float sec);

    StatusCode selectArmPosition(ArmPosition armPosition_);
    StatusCode selectWaitTime(int ms);
    StatusCode selectWaitTime(float sec);

    StatusCode setup(ArmPosition armPosition_, float sec);
private:
    Robot robot;

    int startTime;
    int timeToWait;
    ArmPosition armPosition;

    StatusCode constructor(Robot &robot_, ArmPosition armPosition_, float sec);

    virtual StatusCode initialize();
    virtual StatusCode run();
    virtual bool isFinished();
    virtual StatusCode completion();
};


#endif
