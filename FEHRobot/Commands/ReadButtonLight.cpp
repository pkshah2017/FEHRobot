#include "ReadButtonLight.h"
#include <FEHLCD.h>

ReadButtonLight::ReadButtonLight(Robot &robot_)
{
    robot = robot_;
    buttonColor = Undefined;
}

int ReadButtonLight::initialize() {
    robot.updateSensorStates();

    LCD.WriteRC("CDS VALUE: ", 2 , 1);
    LCD.WriteRC(robot.getCDSState(), 2 , 12);

    if(robot.getCDSState() > .85){
        buttonColor = Blue;
    } else {
        buttonColor = Red;
    }

    return 0;
}

int ReadButtonLight::run() {
    return 0;
}

bool ReadButtonLight::isFinished() {
    return true;
}

int ReadButtonLight::completion(){
    return buttonColor;
}

