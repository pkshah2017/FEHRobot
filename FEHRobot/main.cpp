#include "Subsystems/DriveTrain.h"
#include <FEHLCD.h>

int main(void)
{
    LCD.WriteLine("Program Began");
    DriveTrain robot;

    LCD.WriteLine("Move out of start box");
    robot.driveForTime(0, 1000);
    LCD.WriteLine("Move to the corner");
    robot.driveTilFrontBump(45);
    LCD.WriteLine("Run to the corner");
    robot.driveTilRightBump(90);//til right
    LCD.WriteLine("Run into the switch");
    robot.driveForTime(270, 2500);
    LCD.WriteLine("Back towards the ramp");
    robot.driveForTime(180, 5000);
    LCD.WriteLine("Move towards the buttons");
    robot.driveTilLeftBump(270);//til left
    LCD.WriteLine("Go up the ramp");
    robot.driveForTime(180, 10000);
    LCD.WriteLine("At the top of the ramp");
    /*

    LCD.WriteLine("Move Forward");
    robot.driveForTime(0, 5000);
    LCD.WriteLine("Move Backward");
    robot.driveForTime(180, 5000);
    LCD.WriteLine("Move Right");
    robot.driveForTime(90, 5000);
    LCD.WriteLine("Move Left");
    robot.driveForTime(270, 5000);
     */

    return 0;
}
