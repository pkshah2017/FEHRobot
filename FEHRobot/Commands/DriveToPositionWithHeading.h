#ifndef DRIVETOPOSITIONWITHHEADING
#define DRIVETOPOSITIONWITHHEADING

#include "Command.h"
#include "Robot.h"

class DriveToPositionWithHeading :
    public Command
{
public:
    DriveToPositionWithHeading(Robot &robot_, float x_, float y_, float heading_);

    StatusCode setup(float newX, float newY, float newHeading);

    StatusCode changeXSetpoint(float x_);
    StatusCode changeYSetpoint(float y_);
    StatusCode changeHeadingSetpoint(float heading_);
private:
    Robot robot;
    float x;
    float y;
    float finalHeading;
    float currentX;
    float currentY;
    float currentHeading;
    float startTime;

    virtual StatusCode initialize();
    virtual StatusCode run();
    virtual bool isFinished();
    virtual StatusCode completion();
};

#endif
