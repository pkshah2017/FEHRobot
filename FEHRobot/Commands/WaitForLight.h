/*
 * This command makes the robot wait until the line under the CDS cell turns on. 
*/
#ifndef WAITFORLIGHT
#define WAITFORLIGHT

#include "Command.h"
#include "Robot.h"

class WaitForLight :
    public Command
{
public:
    WaitForLight(Robot *robot_);

    virtual const char* getCommandName();
private:
    Robot *robot;
    float startTime;

    virtual StatusCode initialize();
    virtual StatusCode run();
    virtual bool isFinished();
    virtual StatusCode completion();
};


#endif
