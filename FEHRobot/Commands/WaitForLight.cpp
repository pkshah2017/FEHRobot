#include "WaitForLight.h"
#include <FEHUtility.h>

WaitForLight::WaitForLight(Robot &robot_)
{
    robot = robot_;
}

int WaitForLight::initialize() {
    return 0;
}

int WaitForLight::run() {
    robot.updateSensorStates();
    return 0;
}

bool WaitForLight::isFinished() {
    return robot.getCDSState() < 1.2;
}

int WaitForLight::completion(){

    return 0;
}
