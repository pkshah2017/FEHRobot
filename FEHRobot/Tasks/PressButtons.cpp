#include "PressButtons.h"
#include "FEHLCD.h"

//All commands are initalized assuming the light will be red
//If light is blue, values are modified in failure recovery
PressButtons::PressButtons(Robot &robot_):
    moveArmButtons(robot_),
    moveToButtons(robot_, 0, 50, 0),
    touchButtons(robot_, 340, 50, 500),
    turnIntoButtons(robot_, -25, 250),
    holdButtons(robot_, 2000),
    backSlightyAwayFromButtons(robot_, 180, 50, 150),
    hitButtonsAgain(robot_, 0, 50, 350),
    backAwayFromButtons(robot_, 180, 50, 250),
    raiseArm(robot_, ArmUp, 0),
    moveToWrench(robot_, 270, 50, 3800),
    lowerArm(robot_, ArmRight, 1000),
    liftWrench(robot_, ArmUp, 1000),
    moveTowardStart(robot_, 90, 50, 2250),
    pressFinalButton(robot_, 180, 50, 1950)
{
    robot = robot_;
    addCommand(&moveArmButtons);
    addCommand(&moveToButtons);
    addCommand(&touchButtons);
    addCommand(&turnIntoButtons);
    addCommand(&holdButtons);
    addCommand(&backSlightyAwayFromButtons);
    addCommand(&hitButtonsAgain);
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
        touchButtons.changeHeading(10);
        turnIntoButtons.changePower(25);
        //moveToWrench.changeDriveTime(4000);
    }
    if(error >= 3 && error <= 5){
        error = 0;
    }

    return error;
}
