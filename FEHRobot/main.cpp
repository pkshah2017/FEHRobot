#include <FEHSD.h>
#include <FEHRPS.h>
#include "Robot.h"
#include "Logger.h"

#include "SubPrograms/Jack.h"
#include "SubPrograms/Buttons.h"
#include "Subprograms/Wrench.h"
#include "SubPrograms/Menu.h"

int main(void)
{
    SD.OpenLog();
    RPS.InitializeTouchMenu();
    Robot robot;
    Menu MainMenuSelction(robot);
    MainMenuSelction.ChooseOption();
    SD.CloseLog();
    return 0;
}
