#include "Buttons.h"

Buttons::Buttons(Robot &robot_)
    :driveToButtons(robot_)
{
    robot = robot_;
    addTask(&driveToButtons);
}

