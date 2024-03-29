#include "Logger.h"
#include "TurnCrank.h"
#include "FEHLCD.h"
#include <FEHUtility.h>

//All commands are initalized assuming the light will be red
//If light is blue, values are modified in failure recovery
TurnCrank::TurnCrank(Robot *robot_):
    changeCrankArmPosition(robot_, ArmUp, 500)
{
    robot = robot_;
}

StatusCode TurnCrank::execute(){
    /*
     * Turn the crank
     */
    logger->logMessage("Turning the crank");
    (*robot).updateRPSStates();
    int fuelType = (*robot).getFuelType();
    ArmPosition endPosition = fuelType == 1 ? ArmLeft : ArmRight;
    changeCrankArmPosition.setup(endPosition, 0.5f);
    changeCrankArmPosition.execute();

    //Sleep(300);

    return Success;
}

