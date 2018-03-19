#ifndef CENTERONLINE
#define CENTERONLINE

#include "Command.h"
#include "Robot.h"
class CenterOnLine :
    public Command
{
public:
    CenterOnLine(Robot &robot_);
private:
    Robot robot;
    bool leftOptoOnLine;
    bool centerOptoOnLine;
    bool rightOptoOnLine;

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
