#include "Buttons.h"

Buttons::Buttons(Robot &robot_)
    :driveToButtons(robot_),
      pressButtons(robot_)
{
    robot = robot_;
    addTask(&driveToButtons);
    addTask(&pressButtons);
}

