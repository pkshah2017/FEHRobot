#include "WaitForLight.h"
#include <FEHUtility.h>

WaitForLight::WaitForLight(Robot &robot_)
{
    robot = robot_;
}

int WaitForLight::initialize() {
}

int WaitForLight::run() {
    robot.updateSensorStates();
}

bool WaitForLight::isFinished() {
    return robot.getCDSState() > 1.2;
}
