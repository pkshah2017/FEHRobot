#include "DriveToPosition.h"
#include <FEHUtility.h>
#include <math.h>
#include <FEHLCD.h>

DriveToPosition::DriveToPosition(Robot &robot_, float x_, float y_)
{
    robot = robot_;
    x = x_;
    y = y_;

}

int DriveToPosition::initialize() {
    LCD.WriteLine("Initalizing Drive To Position");
    currentX = robot.getX();
    currentY = robot.getY();

    LCD.WriteLine("Got Robot Position");
    LCD.WriteLine(currentX);
    LCD.WriteLine(currentY);

    return 0;
}

int DriveToPosition::run() {
    currentX = robot.getX();
    currentY = robot.getY();

    LCD.WriteLine("Current Robot Position");
    LCD.WriteLine(currentX);
    LCD.WriteLine(currentY);

    float deltaX = x - currentX;
    float deltaY = y - currentY;

    float error = sqrt(deltaX * deltaX + deltaY * deltaY);
    float heading = atan(deltaY/deltaX) * 180 / PI;

    LCD.WriteLine("Heading is");
    LCD.WriteLine(heading);
    robot.drive(heading, 40);

    return 0;
}

bool DriveToPosition::isFinished() {
    float error = sqrt(currentX * currentX + currentY * currentY);
    LCD.WriteLine("Checking end status");
    LCD.WriteLine(error);
    return abs(error) < POSITION_TOLERANCE;
}

int DriveToPosition::completion(){
    robot.stop();

    return 0;
}
