#include "Jack.h"

Jack::Jack(Robot *robot_)
    :driveToJack(robot_),
      liftJack(robot_),
      driveToGarage(robot_),
      dropOffWrench(robot_)
{
    robot = robot_;
    addTask(&driveToJack);
    addTask(&liftJack);    
    addTask(&driveToGarage);
    addTask(&dropOffWrench);
}

