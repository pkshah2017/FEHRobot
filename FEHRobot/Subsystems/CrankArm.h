/*
 * This is the digital twin of the physical rear crank arm. 
*/
#ifndef CRANKARM
#define CRANKARM

#include <FEHServo.h>
#include "Constants.h"

class CrankArm
{
private:
    FEHServo crankArm;
public:
    CrankArm();

    int setArmPosition(ArmPosition armPosition);
};

#endif
