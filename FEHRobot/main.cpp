#include "Robot.h"
#include "SubPrograms/Jack.h"
#include "SubPrograms/Buttons.h"
#include <FEHRPS.h>

int main(void)
{
    RPS.InitializeTouchMenu();
    Robot robot;
    Buttons buttons(robot);
    buttons.execute();
    //Jack jack(robot);
    //jack.execute();
    /*
    LCD.WriteLine("Program Began");
    Robot robot;
    LCD.WriteLine("Wait for the starting light");
    robot.waitTilStartLight();
    LCD.WriteLine("Move out of start box");
    robot.driveForTime(0, 50, 1000);
    LCD.WriteLine("Move to the corner");
    robot.driveTilFrontBump(45, 50);
    LCD.WriteLine("Run to the corner");
    robot.driveTilRightBump(90, 50);//til right
    LCD.WriteLine("Run into the switch");
    robot.driveForTime(270, 50, 2500);
    LCD.WriteLine("Back towards the ramp");
    robot.driveForTime(180, 50, 5000);
    LCD.WriteLine("Move towards the buttons");
    robot.driveTilLeftBump(270, 50);//til left
    LCD.WriteLine("Go up the ramp");
    robot.driveForTime(180, 50, 10000);
    LCD.WriteLine("At the top of the ramp");
    */
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
