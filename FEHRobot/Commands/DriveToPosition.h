#ifndef DRIVETOPOSITION
#define DRIVETOPOSITION

#include "Command.h"
#include "Robot.h"

class DriveToPosition :
    public Command
{
public:
    DriveToPosition(Robot &robot_, float x_, float y_);

    int changeXSetpoint(float x_);
    int changeYSetpoint(float y_);
private:
    Robot robot;
    float x;
    float y;
    float currentX;
    float currentY;
    float startTime;

    virtual int initialize();
    virtual int run();
    virtual bool isFinished();
    virtual int completion();
};

#endif
