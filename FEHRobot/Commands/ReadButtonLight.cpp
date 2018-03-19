#include "ReadButtonLight.h"
#include <FEHLCD.h>

ReadButtonLight::ReadButtonLight(Robot &robot_)
{
    robot = robot_;
    buttonColor = E_UnreachableCode;
}

StatusCode ReadButtonLight::initialize() {
    robot.updateSensorStates();

    LCD.WriteRC("CDS VALUE: ", 2 , 1);
    LCD.WriteRC(robot.getCDSState(), 2 , 12);

    if(robot.getCDSState() > .85){
        buttonColor = L_Blue;
    } else {
        buttonColor = L_Red;
    }

    return Success;
}

StatusCode ReadButtonLight::run() {
    return Success;
}

bool ReadButtonLight::isFinished() {
    return Success;
}

StatusCode ReadButtonLight::completion(){
    return buttonColor;
}

