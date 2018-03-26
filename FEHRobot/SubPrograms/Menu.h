#ifndef MENU_H
#define MENU_H
#include "Robot.h"
#include "FEHLCD.h"


#include "SubPrograms/Buttons.h"
#include "SubPrograms/Jack.h"
#include "Subprograms/Wrench.h"
#include "SubPrograms/Crank.h"

class Menu
{
private:
    Robot *robot;

    int  mainMenu();
    void  booltoIcon(FEHIcon::Icon inputIcon, int input);
    void  updateIcon(FEHIcon::Icon inputIcon, float input);
    int  runAll();
    int  fullRunMenu();
    int  testingMenu();
    int  diagnosticMenu();
    int RPSCalibrate();
    int  RPSCheck();
    void  clearSystemCheck();
    int  systemCheck();
    int optoCheck();

    Buttons buttons;
    Jack jack;
    Wrench wrench;
    Crank crank;
public:
    Menu(Robot *robot_);
    void ChooseOption();
};
#endif // MENU_H
