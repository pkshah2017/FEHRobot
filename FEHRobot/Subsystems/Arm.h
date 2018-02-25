#ifndef ARM
#define ARM

#include <FEHServo.h>

typedef enum {
    Left, Right, Up
} ArmPosition;

class Arm
{
private:
    FEHServo arm;
public:
    Arm();

    int setArmPosition(ArmPosition armPosition);
};

#endif
