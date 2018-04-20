/*
 * This command reads the button light color using the CDS sensor and returns the value.
*/
#ifndef READBUTTONLIGHT
#define READBUTTONLIGHT

#include "Command.h"
#include "Robot.h"
class ReadButtonLight :
    public Command
{
public:
    ReadButtonLight(Robot *robot_);

    virtual const char* getCommandName();
private:
    Robot *robot;

    StatusCode buttonColor;

    virtual StatusCode initialize();
    virtual StatusCode run();
    virtual bool isFinished();
    virtual StatusCode completion();
};


#endif
