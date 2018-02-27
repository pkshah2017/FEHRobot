#ifndef BUTTONS
#define BUTTONS

#include "Subprogram.h"
#include "Robot.h"
#include "Tasks/DriveToButtons.h"

class Buttons :
    public Subprogram
{
public:
    Buttons(Robot &robot_);
private:
    Robot robot;

    DriveToButtons driveToButtons;
};

#endif
