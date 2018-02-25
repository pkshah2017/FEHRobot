#include "WaitForLight.h"
#include <FEHUtility.h>

#define TIMEOUT 5.0

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
