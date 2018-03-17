#include "CrankArm.h"

CrankArm::CrankArm()
    : crankArm(FEHServo::Servo1)
{
    crankArm.SetMin(527);
    crankArm.SetMax(2348);
}

int CrankArm::setArmPosition(ArmPosition armPosition){
    switch (armPosition) {
    case ArmRight:
        crankArm.SetDegree(ARM_RIGHT_ANGLE);
        break;
    case ArmLeft:
        crankArm.SetDegree(ARM_LEFT_ANGLE);
        break;
    case ArmUp:
        crankArm.SetDegree(ARM_UP_ANGLE);
        break;
    default:
        return 2;
        break;
    }
}
