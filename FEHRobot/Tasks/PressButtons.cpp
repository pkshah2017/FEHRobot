#include "PressButtons.h"

//All commands are initalized assuming the light will be red
//If light is blue, values are modified in failure recovery
PressButtons::PressButtons(Robot &robot_):
    moveArmButtons(robot_),
    moveToButtons(robot_, 0, 50, 0),
    touchButtons(robot_, 340, 50, 500),
    turnIntoButtons(robot_, -25, 250),
    holdButtons(robot_, 6000),
    backAwayFromButtons(robot_, 180, 50, 500),
    raiseArm(robot_, ArmUp, 0),
    moveToWrench(robot_, 270, 50, 3500),
    lowerArm(robot_, ArmRight, 1000),
    liftWrench(robot_, ArmUp, 1000),
    moveTowardStart(robot_, 90, 50, 1500),
    pressFinalButton(robot_, 180, 50, 1350)
{
    robot = robot_;
    addCommand(&moveArmButtons);
    addCommand(&moveToButtons);
    addCommand(&touchButtons);
    addCommand(&turnIntoButtons);
    addCommand(&holdButtons);
    addCommand(&backAwayFromButtons);
    addCommand(&raiseArm);
    addCommand(&moveToWrench);
    addCommand(&lowerArm);
    addCommand(&liftWrench);
    addCommand(&moveTowardStart);
    addCommand(&pressFinalButton);
}

int PressButtons::commandFailureRecovery(int error){
    if(error == 3){
        touchButtons.changeHeading(20);
        turnIntoButtons.changePower(25);
        moveToWrench.changeDriveTime(4000);
    }
    if(error == 3 || error == 4){
        error == 0;
    }

    return 0;
}
