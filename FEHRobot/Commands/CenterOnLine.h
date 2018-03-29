#ifndef CENTERONLINE
#define CENTERONLINE

#include "Command.h"
#include "Robot.h"
class CenterOnLine :
    public Command
{
public:
    CenterOnLine(Robot *robot_, int power);
    StatusCode setup(int newPower);
    virtual const char* getCommandName();
private:
    Robot *robot;
    bool leftOptoOnLine;
    bool centerOptoOnLine;
    bool rightOptoOnLine;
    int power;
    virtual StatusCode initialize();
    virtual StatusCode run();
    virtual bool isFinished();
    virtual StatusCode completion();

    bool checkLeftOpto();
    bool checkCenterOpto();
    bool checkRightOpto();
    void updateOptoStates();
};


#endif
