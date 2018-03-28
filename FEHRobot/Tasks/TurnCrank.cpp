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
    (*robot).updateRPSStates();
    int fuelType = (*robot).getFuelType();
    ArmPosition endPosition = fuelType == 1 ? ArmLeft : ArmRight;
    changeCrankArmPosition.setup(endPosition, .5f);
    changeCrankArmPosition.execute();
    Sleep(750);

    return Success;
}

