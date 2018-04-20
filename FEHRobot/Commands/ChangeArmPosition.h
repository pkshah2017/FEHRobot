/*
 * This command makes the robot change the front arm positon. 
 * This command will end after the specified time has passed. 
 * This command is used to change the arm position to manipulate the wrench.
*/
#ifndef CHANGEARMPOSITION
#define CHANGEARMPOSITION

#include "Command.h"
#include "Robot.h"
class ChangeArmPosition :
        public Command
{
public:
    ChangeArmPosition(Robot *robot_);
    ChangeArmPosition(Robot *robot_, ArmPosition armPosition_, int ms);
    ChangeArmPosition(Robot *robot_, ArmPosition armPosition_, float sec);

    StatusCode selectArmPosition(ArmPosition armPosition_);
    StatusCode selectWaitTime(int ms);
    StatusCode selectWaitTime(float sec);

    StatusCode setup(ArmPosition armPosition_, float sec);
    StatusCode setup(ArmPosition armPosition_, int ms);

    virtual const char* getCommandName();
private:
    Robot *robot;

    float startTime;
    float timeToWait;
    ArmPosition armPosition;

    StatusCode constructor(Robot *robot_, ArmPosition armPosition_, float sec);

    virtual StatusCode initialize();
    virtual StatusCode run();
    virtual bool isFinished();
    virtual StatusCode completion();
};


#endif
