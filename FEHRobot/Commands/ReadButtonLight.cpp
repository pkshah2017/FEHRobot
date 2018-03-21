#include "ReadButtonLight.h"
#include <FEHLCD.h>

ReadButtonLight::ReadButtonLight(Robot *robot_)
{
    robot = robot_;
    buttonColor = E_UnreachableCode;
}

StatusCode ReadButtonLight::initialize() {
    (*robot).updateSensorStates();

    if((*robot).getCDSState() < .85){
        buttonColor = L_Red;
    } else {
        buttonColor = L_Blue;
    }
    return Success;
}

StatusCode ReadButtonLight::run() {
    return Success;
}

bool ReadButtonLight::isFinished() {
    return true;
}

StatusCode ReadButtonLight::completion(){
    return buttonColor;
}

