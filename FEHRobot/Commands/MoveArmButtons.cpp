#include "MoveArmButtons.h"
#include <FEHUtility.h>
#include <FEHLCD.h>

MoveArmButtons::MoveArmButtons(Robot &robot_)
{
    robot = robot_;
    timeToWait = MOVE_ARM_WAIT;
    LightStatus = 5;
}

int MoveArmButtons::initialize() {
    robot.updateSensorStates();

    LCD.WriteRC("CDS VALUE: ", 2 , 1);
    LCD.WriteRC(robot.getCDSState(), 2 , 12);

    startTime = TimeNow();

    if(robot.getCDSState() > .85){
        robot.setArmPosition(ArmLeft);
        LCD.WriteRC("Blue", 3, 1);
        LightStatus = 3;
    } else {
        robot.setArmPosition(ArmRight);
        LCD.WriteRC("Red", 3, 1);
        LightStatus = 4;
    }

    return 0;
}

int MoveArmButtons::run() {
    return 0;
}

bool MoveArmButtons::isFinished() {
    return TimeNow() - startTime > timeToWait;
}

int MoveArmButtons::completion(){
    return LightStatus;
}

