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

    ButtonColor buttonColor;

    virtual int initialize();
    virtual int run();
    virtual bool isFinished();
    virtual int completion();
};


#endif
