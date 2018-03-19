#include "Robot.h"

#include "SubPrograms/Jack.h"
#include "SubPrograms/Buttons.h"
#include "Subprograms/Wrench.h"
#include "SubPrograms/Menu.h"
#include <FEHRPS.h>

int main(void)
{
    RPS.InitializeTouchMenu();
    Robot robot;
    Menu MainMenuSelction(robot);
    MainMenuSelction.ChooseOption();

    return 0;
}
