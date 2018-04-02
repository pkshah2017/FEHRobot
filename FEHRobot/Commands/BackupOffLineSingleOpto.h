#ifndef BACKUPOFFLINESINGLEOPTO
#define BACKUPOFFLINESINGLEOPTO

#include "Command.h"
#include "Robot.h"

class BackupOffLineSingleOpto :
    public Command
{
public:
    BackupOffLineSingleOpto(Robot *robot_, int power_);

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
