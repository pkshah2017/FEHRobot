/*
 * This command makes the robot drive to the specified RPS location. It uses RPS and drives
 * in a straight line to the RPS location. It also makes sure the ending RPS heading is 
 * the one specified. 
*/
#ifndef DRIVETOPOSITIONWITHHEADING
#define DRIVETOPOSITIONWITHHEADING

#include "Command.h"
#include "Robot.h"

class DriveToPositionWithHeading :
    public Command
{
public:
    DriveToPositionWithHeading(Robot *robot_, float x_, float y_, float heading_);

    StatusCode setup(float newX, float newY, float newHeading);

    StatusCode changeXSetpoint(float x_);
    StatusCode changeYSetpoint(float y_);
    StatusCode changeHeadingSetpoint(float heading_);

    virtual const char* getCommandName();
private:
    Robot *robot;
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
