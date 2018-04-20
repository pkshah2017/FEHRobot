/*
 * This command makes the robot center on the lines using the front optos. 
 * This command is used in the DriveToButtons Task.
*/
#ifndef CENTERONLINE
#define CENTERONLINE

#include "Command.h"
#include "Robot.h"
class CenterOnLine :
    public Command
{
public:
    CenterOnLine(Robot *robot_, int power);
    StatusCode setup(int newPower);
    virtual const char* getCommandName();
private:
    Robot *robot;
    bool leftOptoOnLine;
    bool centerOptoOnLine;
    bool rightOptoOnLine;
    int power;

    bool isMovingLeft;
    int numberOfReversals;


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
