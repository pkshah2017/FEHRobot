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
