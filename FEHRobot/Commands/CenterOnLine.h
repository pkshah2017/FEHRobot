#ifndef CENTERONLINE
#define CENTERONLINE

#include "Command.h"
#include "Robot.h"
class CenterOnLine :
    public Command
{
public:
    CenterOnLine(Robot &robot_);

    int setRobot(Robot &robot_);
private:
    Robot robot;
    bool leftOptoStatus;
    bool centerOptoStatus;
    bool rightOptoStatus;

    virtual int initialize();
    virtual int run();
    virtual bool isFinished();
    virtual int completion();

    bool checkLeftOpto();
    bool checkCenterOpto();
    bool checkRightOpto();
    void updateOptoStates();
};


#endif
