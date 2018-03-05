#include "Arm.h"

Arm::Arm()
    : arm(FEHServo::Servo0)
{
    arm.SetMin(557);
    arm.SetMax(2348);
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
    case ArmAngledRight:
        arm.SetDegree(ARM_ANGLED_RIGHT_ANGLE);
        break;
    default:
        return 2;
        break;
    }
}
