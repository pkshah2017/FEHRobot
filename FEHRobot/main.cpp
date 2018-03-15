#include "Robot.h"
#include "SubPrograms/Jack.h"
#include "SubPrograms/Buttons.h"
#include "Subprograms/Wrench.h"
#include <FEHRPS.h>

int main(void)
{
    RPS.InitializeTouchMenu();
    Robot robot;
    Wrench wrench(robot);
    wrench.execute();


    return 0;
}
