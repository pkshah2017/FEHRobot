#ifndef CONSTANTS
#define CONSTANTS

//ARM CONSTANTS
#define ARM_LEFT_ANGLE 180
#define ARM_RIGHT_ANGLE 0
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

//SENSOR CONSTANTS
typedef enum {
    LeftOpto, CenterOpto, RightOpto
} OptoSelection;

//COMMAND CONSTANTS
#define REFRESH_RATE 20

//DRIVE TIL BUMP CONSTANTS
#define TIMEOUT 5000.0

//DRIVE TO POSITION CONSTANTS
#define POSITION_TOLERANCE 1.5

//Move Arm Constants
#define MOVE_ARM_WAIT 2.0

//LINE FOLLOW FOR TIME CONSTANTS
typedef enum {
    OFF_ON_OFF, ON_ON_OFF, ON_OFF_OFF, OFF_ON_ON, OFF_OFF_ON, OFF_OFF_OFF, ON_ON_ON
} LineFollowerState;

//TASK CONSTANTS
#define MAX_COMMANDS 20

//Press Buttons Constants
typedef enum {
    Blue, Red
} ButtonColor;

//SUBPROGRAM CONSTANTS
#define MAX_TASKS 20

#endif
