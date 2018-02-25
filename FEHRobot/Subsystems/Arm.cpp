#include "Arm.h"


#define ARM_LEFT_ANGLE 0
#define ARM_RIGHT_ANGLE 180
#define ARM_UP_ANGLE 90

Arm::Arm()
    : arm(FEHServo::Servo0)
{
    arm.SetMin(0);
    arm.SetMax(0);
}

Arm::setArmPosition(ArmPosition armPosition){
    switch (armPosition) {
    case Right:
        arm.SetDegree(ARM_RIGHT_ANGLE);
        break;
    case Left:
        arm.SetDegree(ARM_LEFT_ANGLE);
        break;
    case Up:
        arm.SetDegree(ARM_UP_ANGLE);
        break;
    default:
        return 2;
        break;
    }
}
