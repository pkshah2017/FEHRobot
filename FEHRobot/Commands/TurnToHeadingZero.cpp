#include "Logger.h"
#include "TurnToHeadingZero.h"
#include "math.h"
#include <FEHUtility.h>

//Positive Power is to the right

TurnToHeadingZero::TurnToHeadingZero(Robot *robot_, int power_)
{
    robot = robot_;
    power = power_;
}

StatusCode TurnToHeadingZero::setup(int newPower){
    power = newPower;
}

StatusCode TurnToHeadingZero::initialize() {
    robot->updateRPSStates();
    return Success;
}

StatusCode TurnToHeadingZero::run() {
    robot->updateRPSStates();
    float currentHeading = robot->getHeading();
    int multiplier = currentHeading < 180 ? 1 : -1;
    (*robot).turn(power * multiplier);
    return Success;
}

bool TurnToHeadingZero::isFinished() {
    float currentHeading = robot->getHeading();
    int tolerance = 3;
    return abs(355 - currentHeading) < tolerance;
   // return currentHeading < tolerance || currentHeading > (360 - tolerance);
}

StatusCode TurnToHeadingZero::completion(){
    (*robot).stop();

    return Success;
}

const char * TurnToHeadingZero::getCommandName(){
    return "TurnToHeadingZero";
}
