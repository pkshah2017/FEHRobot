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

//COMMAND CONSTANTS
#define REFRESH_RATE 20

//DRIVE TIL BUMP CONSTANTS
#define TIMEOUT 5000.0

//TASK CONSTANTS
#define MAX_COMMANDS 20

//SUBPROGRAM CONSTANTS
#define MAX_TASKS 20

#endif
