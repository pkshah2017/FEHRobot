#include "DriveToCrank.h"

DriveToCrank::DriveToCrank(Robot *robot_):
    driveForTime(robot_,0,0,0),
    driveToPosition(robot_, 0, 0),
    driveToPositionWithHeading(robot_,0,0,45),
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

    driveToPosition.changeXSetpoint(24.6f);
    driveToPosition.changeYSetpoint(65.8f);
    driveToPosition.execute();
    /*
     * DO NOT delete this
     * backaway from crank a bit
     */
    driveForTime.setup(0,30,150);
    driveForTime.execute();
    return Success;
}

