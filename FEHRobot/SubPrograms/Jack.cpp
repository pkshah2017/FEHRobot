#include "Jack.h"

Jack::Jack(Robot &robot_)
    :driveToJack(robot_),
      liftJack(robot_)
{
    robot = robot_;
    addTask(&driveToJack);
    addTask(&liftJack);
}

