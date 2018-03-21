#include "DriveToCrank.h"

DriveToCrank::DriveToCrank(Robot *robot_):
    driveToPosition(robot_, 0, 0),
    changeCrankArmPosition(robot_, ArmUp, 500)
{
    robot = robot_;
}

StatusCode DriveToCrank::execute(){
    /*
     * Setup to turn the crank
     */
    (*robot).updateRPSStates();
    int fuelType = (*robot).getFuelType();
    ArmPosition startPosition = fuelType == 1 ? ArmRight : ArmLeft;
    changeCrankArmPosition.setup(startPosition, .5f);
    changeCrankArmPosition.execute();

    /*
     * Go To Crank
     */
    driveToPosition.changeXSetpoint(24.8f);
    driveToPosition.changeYSetpoint(66.3f);
    driveToPosition.execute();

    return Success;
}

