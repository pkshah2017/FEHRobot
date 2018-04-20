/*
 * This command makes the robot change the rear arm positon. 
 * This command will end after the specified time has passed. 
 * This command is used to change the rear arm position to manipulate the crank.
*/
#ifndef CHANGECRANKARMPOSITION
#define CHANGECRANKARMPOSITION

#include "Command.h"
#include "Robot.h"
class ChangeCrankArmPosition :
        public Command
{
public:
    ChangeCrankArmPosition(Robot *robot_);
    ChangeCrankArmPosition(Robot *robot_, ArmPosition armPosition_, int ms);
    ChangeCrankArmPosition(Robot *robot_, ArmPosition armPosition_, float sec);

    StatusCode selectArmPosition(ArmPosition armPosition_);
    StatusCode selectWaitTime(int ms);
    StatusCode selectWaitTime(float sec);

    StatusCode setup(ArmPosition armPosition_, float sec);

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
