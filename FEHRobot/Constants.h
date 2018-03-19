#ifndef CONSTANTS
#define CONSTANTS

/*
 * Subsystem Constants
 */

//Arm Position Angles
#define ARM_LEFT_ANGLE 180
#define ARM_RIGHT_ANGLE 0
#define ARM_UP_ANGLE 90
#define ARM_ANGLED_RIGHT_ANGLE 45
#define ARM_SLIGHTLY_RAISED_ANGLE 20

//Arm Position Names
typedef enum {
    ArmLeft, ArmRight, ArmUp, ArmAngledRight, ArmSlightlyRaised
} ArmPosition;

//Drive Train Calculation Constants
#define MOTOR_VOLTAGE 7.2
#define PI 3.14159265358

//Bump Switch Names
typedef enum {
    RobotFront, RobotLeft, RobotRight
} Direction;

//Opto Sensor Names
typedef enum {
    LeftOpto, CenterOpto, RightOpto
} OptoSelection;

/*
 * Command Constants
 */

#define REFRESH_RATE 20
#define TIMEOUT 5000.0
#define POSITION_TOLERANCE 1.0

//Line Follower States
typedef enum {
    OFF_ON_OFF, ON_ON_OFF, ON_OFF_OFF, OFF_ON_ON, OFF_OFF_ON, OFF_OFF_OFF, ON_ON_ON
} LineFollowerState;

/*
 * Task Constants
 */
#define MAX_COMMANDS 20

//Button Colors
typedef enum {
    Blue, Red, Undefined
} ButtonColor;

/*
 * SubProgram Constants
 */
#define MAX_TASKS 20

/*
 * Error Codes
 */

typedef enum {
    Success, L_Red, L_Blue, E_Timeout, E_InvalidInput, E_LightNotDetected , E_UnreachableCode
} StatusCode;
/*
struct _errordesc {
    int  code;
    const char *message;
} errordesc[] = {
{ Success, "Sucess" },
{ L_Red, "Red Light Detected" },
{ L_Blue, "Blue Light Detected" },
{ E_Timeout, "Timeout" },
{ E_InvalidInput, "Invalid input" },
{ E_LightNotDetected, "Light Not Detected" },
{ E_UnreachableCode, "Unreachable Code Reached" }
};
*/
#endif
