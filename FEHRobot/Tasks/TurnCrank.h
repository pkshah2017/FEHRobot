#ifndef TURNCRANK
#define TURNCRANK

#include "Task.h"
#include "Robot.h"
#include "Commands/CommandList.h"

class TurnCrank :
    public Task
{
public:
    TurnCrank(Robot &robot_);

    virtual StatusCode execute();
private:
    Robot robot;

    ChangeCrankArmPosition changeCrankArmPosition;
};

#endif
