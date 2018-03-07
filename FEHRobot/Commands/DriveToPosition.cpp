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

int DriveToPosition::changeXSetpoint(float x_){
    x = x_;
}

int DriveToPosition::changeYSetpoint(float y_){
    y = y_;
}

int DriveToPosition::initialize() {
    robot.updateRPSStates();
    currentX = robot.getX();
    currentY = robot.getY();

    LCD.WriteLine(currentX);
    LCD.WriteLine(currentY);

    return 0;
}

int DriveToPosition::run() {
    robot.updateRPSStates();
    currentX = robot.getX();
    currentY = robot.getY();

    float deltaX = x - currentX;
    float deltaY = y - currentY;

    float error = sqrt(deltaX * deltaX + deltaY * deltaY);
    float heading = atan(deltaY/deltaX) * 180 / PI;
    if(deltaX < 0 && deltaY > 0){
        heading = 180 + heading;
    } else if(deltaX < 0 && deltaY < 0){
        heading = 180 + heading;
    } else if (deltaX > 0 && deltaY < 0){
        heading += 360;
    }
    heading += 90;

    robot.drive(heading, 30);

    return 0;
}

bool DriveToPosition::isFinished() {
    float deltaX = x - currentX;
    float deltaY = y - currentY;

    float error = sqrt(deltaX * deltaX + deltaY * deltaY);

    return abs(error) <= POSITION_TOLERANCE;
}

int DriveToPosition::completion(){
    robot.stop();

    return 0;
}
