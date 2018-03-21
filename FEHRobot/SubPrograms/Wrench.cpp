#include "Wrench.h"

Wrench::Wrench(Robot *robot_)
    :driveToWrench(robot_),
      pickUpWrench(robot_),
      driveToGarage(robot_),
      dropOffWrench(robot_)
{
    robot = robot_;
    addTask(&driveToWrench);
    addTask(&pickUpWrench);
    addTask(&driveToGarage);
    addTask(&dropOffWrench);
}

