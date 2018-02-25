#include "Arm.h"

Arm::Arm()
    : arm(FEHServo::Servo0)
{
    arm.SetMin(0);
    arm.SetMax(0);
}

int Arm::setArmPosition(ArmPosition armPosition){
    switch (armPosition) {
    case ArmRight:
        arm.SetDegree(ARM_RIGHT_ANGLE);
        break;
    case ArmLeft:
        arm.SetDegree(ARM_LEFT_ANGLE);
        break;
    case ArmUp:
        arm.SetDegree(ARM_UP_ANGLE);
        break;
    default:
        return 2;
        break;
    }
}