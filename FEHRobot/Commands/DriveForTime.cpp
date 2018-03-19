#include "DriveForTime.h"
#include <FEHUtility.h>

DriveForTime::DriveForTime(Robot &robot_, int heading_, int power_, float sec_)
{
    robot = robot_;
    StatusCode status = setup(heading_, power_, sec_);
    if(status != Success){
        LCD.Write("ERROR CODE: ");
        LCD.WriteLine((int)status);
        LCD.Write("Description: ");
        //LCD.WriteLine(errordesc[(int)status].message);
    }
}

DriveForTime::DriveForTime(Robot &robot_, int heading_, int power_, int ms)
{
    robot = robot_;
    StatusCode status = setup(heading_, power_, ms);
    if(status != Success){
        LCD.Write("ERROR CODE: ");
        LCD.WriteLine((int)status);
        LCD.Write("Description: ");
        //LCD.WriteLine(errordesc[(int)status].message);
    }
}

StatusCode DriveForTime::setup(int newHeading,int newPower, int newTime){
    return setup(newHeading, newPower, newTime/1000.0f);
}

StatusCode DriveForTime::setup(int newHeading,int newPower, float newTime){
    StatusCode status = changeHeading(newHeading);
    if(status == Success){
        status = changePower(newPower);
    }
    if(status == Success){
        status = changeDriveTime(newTime);
    }
    return status;
}

StatusCode DriveForTime::changeHeading(int newHeading){
    heading = newHeading;
    return Success;
}

StatusCode DriveForTime::changePower(int newPower){
    power = newPower;
    return Success;
}

StatusCode DriveForTime::changeDriveTime(int newTime){
    timeToWait = newTime/1000.0;
    return Success;
}

StatusCode DriveForTime::changeDriveTime(float newTime){
    timeToWait = newTime;
    return Success;
}

StatusCode DriveForTime::initialize() {
    startTime = TimeNow();

    return Success;
}

StatusCode DriveForTime::run() {
    robot.drive(heading, power);

    return Success;
}

bool DriveForTime::isFinished() {
    return TimeNow() - startTime > timeToWait;
}

StatusCode DriveForTime::completion(){
    robot.stop();

    return Success;
}
