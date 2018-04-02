#ifndef BACKUPTOLINESINGLEOPTO
#define BACKUPTOLINESINGLEOPTO

#include "Command.h"
#include "Robot.h"

class BackupToLineSingleOpto :
    public Command
{
public:
    BackupToLineSingleOpto(Robot *robot_, int power_);

    StatusCode changePower(int newPower);

    virtual const char* getCommandName();
private:
    Robot *robot;
    int power;
    bool onLine;

    virtual StatusCode initialize();
    virtual StatusCode run();
    virtual bool isFinished();
    virtual StatusCode completion();

    StatusCode updateLineFollowerState(float optoThreshold);
};

#endif
