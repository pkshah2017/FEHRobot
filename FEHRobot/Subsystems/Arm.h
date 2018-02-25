#ifndef ARM
#define ARM

#include <FEHServo.h>
#include "Constants.h"

class Arm
{
private:
    FEHServo arm;
public:
    Arm();

    int setArmPosition(ArmPosition armPosition);
};

#endif
