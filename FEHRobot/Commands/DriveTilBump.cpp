#include "DriveTilBump.h"
#include <FEHUtility.h>

DriveTilBump::DriveTilBump(Robot *robot_, int heading_, int power_, Direction direction_)
{
    robot = robot_;
    StatusCode status = setup(heading_, power_, direction_);
    if(status != Success){
        LCD.Write("ERROR CODE: ");
        LCD.WriteLine((int)status);
        LCD.Write("Description: ");
        //LCD.WriteLine(errordesc[(int)status].message);
    }
}

StatusCode DriveTilBump::setup(int newHeading, int newPower , Direction newDirection){
    StatusCode status = changeHeading(newHeading);
    if(status == Success){
        status = changePower(newPower);
    }
    if(status == Success){
        status = changeBumpDirection(newDirection);
    }
    return status;
}

StatusCode DriveTilBump::changeHeading(int newHeading){
    heading = newHeading;
    return Success;
}

StatusCode DriveTilBump::changePower(int newPower){
    power = newPower;
    return Success;
}

StatusCode DriveTilBump::changeBumpDirection(Direction direction_){
    direction = direction_;
    return Success;
}

StatusCode DriveTilBump::initialize() {
    startTime = TimeNow();
    (*robot).updateSensorStates();

    return Success;
}

StatusCode DriveTilBump::run() {
    (*robot).drive(heading, power);
    (*robot).updateSensorStates();
    if(TimeNow() - startTime > TIMEOUT){
        return E_Timeout;
    }
    return Success;
}

StatusCode DriveTilBump::runFailureRecovery(StatusCode error){
    if(error == E_Timeout){
        (*robot).stop();
    }
    return error;
}

bool DriveTilBump::isFinished() {
    return !(*robot).getLimit(direction);
}

StatusCode DriveTilBump::completion(){
    (*robot).stop();

    return Success;
}

