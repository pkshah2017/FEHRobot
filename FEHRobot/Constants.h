#ifndef CONSTANTS
#define CONSTANTS

//ARM CONSTANTS
#define ARM_LEFT_ANGLE 0
#define ARM_RIGHT_ANGLE 180
#define ARM_UP_ANGLE 90

typedef enum {
    ArmLeft, ArmRight, ArmUp
} ArmPosition;


//DRIVE TRAIN CONSTANTS
#define MOTOR_VOLTAGE 7.2
#define PI 3.14159265358

typedef enum {
    RobotFront, RobotLeft, RobotRight
} Direction;


#endif
