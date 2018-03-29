#ifndef TURNTOHEADINGZERO
#define TURNTOHEADINGZERO

#include "Command.h"
#include "Robot.h"

class TurnToHeadingZero :
    public Command
{
public:
    TurnToHeadingZero(Robot *robot_, int power_);
    StatusCode setup(int newPower);

    virtual const char* getCommandName();
private:
    Robot *robot;
    int power;

    virtual StatusCode initialize();
    virtual StatusCode run();
    virtual bool isFinished();
    virtual StatusCode completion();
};

#endif
