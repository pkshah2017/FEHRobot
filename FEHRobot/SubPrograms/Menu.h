#ifndef MENU_H
#define MENU_H
#include "Robot.h"

class Menu
{
private:
    Robot robot;
public:
    void ChooseOption(Robot &robot_);
};
extern Menu MainMenu;
#endif // MENU_H
