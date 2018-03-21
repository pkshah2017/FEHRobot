#include "Crank.h"

Crank::Crank(Robot *robot_)
    :driveToCrank(robot_),
      turnCrank(robot_),
      driveToEnd(robot_)
{
    robot = robot_;
    addTask(&driveToCrank);
    addTask(&turnCrank);
    addTask(&driveToEnd);
}

