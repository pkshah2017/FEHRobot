#include <FEHSD.h>
#include <FEHRPS.h>
#include "Robot.h"
#include "Logger.h"

#include "SubPrograms/Jack.h"
#include "SubPrograms/Buttons.h"
#include "Subprograms/Wrench.h"
#include "SubPrograms/Menu.h"

Robot robot;
Logger logger(&robot);

int main(void)
{
    SD.OpenLog();
    logger.logMessage("Starting Main Program\n");
    RPS.InitializeTouchMenu();
    Menu MainMenuSelction(&robot);
    MainMenuSelction.ChooseOption();
    SD.CloseLog();
    return 0;
}
