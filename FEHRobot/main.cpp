#include <FEHSD.h>
#include <FEHRPS.h>
#include "Robot.h"
#include "Logger.h"

#include "SubPrograms/Jack.h"
#include "SubPrograms/Buttons.h"
#include "Subprograms/Wrench.h"
#include "SubPrograms/Menu.h"

Logger *logger;

int main(void)
{
    Robot robot;
    logger = new Logger(&robot);
    SD.OpenLog();
    logger -> logMessage("Starting Main Program\r\n");
    //RPS.InitializeTouchMenu();
    logger -> logMessage("Initialized Touch Menu\r\n");
    Menu MainMenuSelction(&robot);
    MainMenuSelction.ChooseOption();
    delete logger;
    SD.CloseLog();
    return 0;
}
