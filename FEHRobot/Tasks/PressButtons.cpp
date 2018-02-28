#include "PressButtons.h"

PressButtons::PressButtons(Robot &robot_):
    moveArmButtons(robot_),
    moveToButtons(robot_, 0, 50, 0),
    touchButtons(robot_, 340, 50, 500),
    turnIntoButtons(robot_, -25, 250),
    holdButtons(robot_, 6000),
    backAwayFromButtons(robot_, 180, 50, 500),
    moveToWrench(robot_, 270, 50, 3000),
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
    addCommand(&moveToWrench);
    addCommand(&moveTowardStart);
    addCommand(&pressFinalButton);
}

