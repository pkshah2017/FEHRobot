#include "Logger.h"
#include "WaitForLight.h"
#include <FEHUtility.h>

WaitForLight::WaitForLight(Robot *robot_)
{
    robot = robot_;
    startTime = 0.0f;
}

StatusCode WaitForLight::initialize() {
    startTime = TimeNow();
    return Success;
}

StatusCode WaitForLight::run() {
    (*robot).updateSensorStates();
    return Success;
}

bool WaitForLight::isFinished() {
    return (*robot).getCDSState() < 1.2 || TimeNow() - startTime > 29.0f;
}

StatusCode WaitForLight::completion(){
    logger->resetRunStartTime();
    return Success;
}

const char * WaitForLight::getCommandName(){
    return "WaitForLight";
}
