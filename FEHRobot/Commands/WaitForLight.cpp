#include "Logger.h"
#include "WaitForLight.h"
#include <FEHUtility.h>

WaitForLight::WaitForLight(Robot *robot_)
{
    robot = robot_;
}

StatusCode WaitForLight::initialize() {
    logger -> logMessageScreen("Waiting For Light");
    return Success;
}

StatusCode WaitForLight::run() {
    (*robot).updateSensorStates();
    return Success;
}

bool WaitForLight::isFinished() {
    return (*robot).getCDSState() < 1.2;
}

StatusCode WaitForLight::completion(){
    logger -> logMessageScreen("Detected Light");
    return Success;
}
