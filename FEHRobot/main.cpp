#include "Robot.h"

#include "SubPrograms/Jack.h"
#include "SubPrograms/Buttons.h"
#include "Subprograms/Wrench.h"
#include "Subprograms/Menu.h"
#include <FEHRPS.h>

int main(void)
{
    RPS.InitializeTouchMenu();
    Robot robot;
    MainMenu.ChooseOption(robot);


    return 0;
}
