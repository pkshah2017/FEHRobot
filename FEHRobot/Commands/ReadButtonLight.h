#ifndef READBUTTONLIGHT
#define READBUTTONLIGHT

#include "Command.h"
#include "Robot.h"
class ReadButtonLight :
    public Command
{
public:
    ReadButtonLight(Robot &robot_);
private:
    Robot robot;

    StatusCode buttonColor;

    virtual StatusCode initialize();
    virtual StatusCode run();
    virtual bool isFinished();
    virtual StatusCode completion();
};


#endif
