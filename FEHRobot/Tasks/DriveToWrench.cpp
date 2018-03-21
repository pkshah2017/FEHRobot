#include "DriveToWrench.h"
#include "FEHLCD.h"

DriveToWrench::DriveToWrench(Robot *robot_):
    waitForLight(robot_),
    driveForTime(robot_, 0, 50, 1350),
    driveToPosition(robot_, 0, 0),
    changeArmPosition(robot_, ArmUp, 500),
    driveToPositionWithHeading(robot_, 0, 0, 180)
{
    robot = robot_;
}

StatusCode DriveToWrench::execute(){
    /*
     * Drive to wrench
     */
    //driveToPosition.setup(7.5f, 21.0f);
    //driveToPosition.execute();
    driveToPositionWithHeading.setup(7.5f, 21.0f, 0);
    driveToPositionWithHeading.execute();
    (*robot).updateRPSStates();
    LCD.WriteRC("LOCATION X and Y: ", 6, 1);
    LCD.WriteRC((*robot).getX(), 7, 1);
    LCD.WriteRC((*robot).getY(), 8, 1);


    return Success;
}

