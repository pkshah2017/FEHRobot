#include "WaitForLight.h"
#include <FEHUtility.h>

WaitForLight::WaitForLight(Robot &robot_)
{
    robot = robot_;
}

StatusCode WaitForLight::initialize() {
    return Success;
}

StatusCode WaitForLight::run() {
    robot.updateSensorStates();
    return Success;
}

bool WaitForLight::isFinished() {
    return robot.getCDSState() < 1.2;
}

StatusCode WaitForLight::completion(){
    return Success;
}
