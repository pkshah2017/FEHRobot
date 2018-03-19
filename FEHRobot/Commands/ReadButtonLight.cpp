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

    LCD.WriteRC("LIGHT VALUE: ", 2 , 1);
    LCD.WriteRC(buttonColor, 2 , 15);
    return Success;
}

StatusCode ReadButtonLight::run() {
    LCD.WriteLine("RAN RUN FOR RBL");
    return Success;
}

bool ReadButtonLight::isFinished() {
    return true;
}

StatusCode ReadButtonLight::completion(){
    return buttonColor;
}

