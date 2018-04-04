#include "DriveToCrank.h"

DriveToCrank::DriveToCrank(Robot *robot_):
    driveForTime(robot_,0,0,0),
    driveToPosition(robot_, 0, 0),    
    turnForTime(robot_, -25, 250),
    driveToPositionWithHeading(robot_,0,0,45),
    changeCrankArmPosition(robot_, ArmUp, 0.0f),
    changeArmPosition(robot_, ArmUp, 0.0f)
{
    robot = robot_;
}

StatusCode DriveToCrank::execute(){


    /*
     * Exit garage
     */
    driveForTime.setup(90, 60, 400);
    driveForTime.execute();

    /*
     * Move Arm up
     */
    changeArmPosition.setup(ArmUp, 0.0f);
    changeArmPosition.execute();

    /*
     * Go back into garage
     */
    driveForTime.setup(270, 60, 600);
    driveForTime.execute();

    /*
     * Leave the Garage
     */
    //driveForTime.setup(90, 60, 1600);
    //driveForTime.execute();

    float startTime = TimeNow();

    int turnSpeed = -2;
    if(RPS.CurrentRegionLetter() == 'E' || RPS.CurrentRegionLetter() == 'C'){
        turnSpeed = -1;
    }


    while(TimeNow()-startTime<1.640){
    (*robot).driveAndTurn(90, 60, turnSpeed);
    }

    /*
     * Setup to turn the crank
     */
    (*robot).updateRPSStates();
    int fuelType = (*robot).getFuelType();

    ArmPosition startPosition = fuelType == 1 ? ArmRight : ArmLeft;
    changeCrankArmPosition.setup(startPosition, 0.0f);
    changeCrankArmPosition.execute();

    /*
     * Go To Crank
     */

    //driveToPosition.changeXSetpoint(26.0f);
    //driveToPosition.changeYSetpoint(64.4f);
    //driveToPosition.execute();

    //driveForTime.setup(90,70,1.0f);
    //driveForTime.execute();
    driveForTime.setup(180,70,1.15f);
    driveForTime.execute();

    //turnForTime.setup(-40,100);
    //turnForTime.execute();

    /*
     * DO NOT delete this
     * backaway from crank a bit
     */
   driveForTime.setup(0,30,70);
   driveForTime.execute();
    return Success;
}

