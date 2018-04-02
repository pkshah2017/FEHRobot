#ifndef BACKUPTOWHITELINE
#define BACKUPTOWHITELINE

#include "Command.h"
#include "Robot.h"

class BackupToWhiteLine :
    public Command
{
public:
    BackupToWhiteLine(Robot *robot_, int power_);

    StatusCode changePower(int newPower);

    virtual const char* getCommandName();
private:
    Robot *robot;
    int power;
    LineFollowerState lineFollowStatus;

    virtual StatusCode initialize();
    virtual StatusCode run();
    virtual bool isFinished();
    virtual StatusCode completion();

    StatusCode updateLineFollowerState(float leftThreshold, float centerThreshold, float rightTheshold);
};

#endif
