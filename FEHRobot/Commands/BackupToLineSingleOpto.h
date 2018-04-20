/*
 * This command makes the robot backup until center set of optos is over the line.
 * At the end of this command the robot will be "parallel" to the line.
 * This command is used in the DriveToGarage Task.
*/
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
    float startTime;
    bool onLine;

    virtual StatusCode initialize();
    virtual StatusCode run();
    virtual bool isFinished();
    virtual StatusCode completion();

    StatusCode updateLineFollowerState(float optoThreshold);
};

#endif
