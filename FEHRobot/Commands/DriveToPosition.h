#ifndef DRIVETOPOSITION
#define DRIVETOPOSITION

#include "Command.h"
#include "Robot.h"

class DriveToPosition :
    public Command
{
public:
    DriveToPosition(Robot *robot_, float x_, float y_);

    StatusCode setup(float newX, float newY);

    StatusCode changeXSetpoint(float x_);
    StatusCode changeYSetpoint(float y_);
private:
    Robot *robot;
    float x;
    float y;
    float currentX;
    float currentY;
    float startTime;

    virtual StatusCode initialize();
    virtual StatusCode run();
    virtual bool isFinished();
    virtual StatusCode completion();
};

#endif
