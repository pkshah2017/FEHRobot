#ifndef CONSTANTS
#define CONSTANTS

/*
 * Subsystem Constants
 */

//Arm Position Angles
#define ARM_LEFT_ANGLE 180
#define ARM_RIGHT_ANGLE 0
#define ARM_UP_ANGLE 80
#define ARM_VERTICAL_ANGLE 92
#define ARM_ANGLED_RIGHT_ANGLE 25
#define ARM_SLIGHTLY_RAISED_ANGLE 8

//Arm Position Names
typedef enum {
    ArmLeft, ArmRight, ArmUp, ArmVertical, ArmAngledRight, ArmSlightlyRaised
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
    LeftOpto, CenterOpto, RightOpto, CornerOpto
} OptoSelection;

/*
 * Command Constants
 */

#define REFRESH_RATE 20
#define TIMEOUT 7.0f
#define RPS_TIMEOUT 5.0f
#define BUMP_TIMEOUT 1.0f
#define BACKUP_TIMEOUT 1.14f
#define BACKUP_SINGLE_OPTO_TIMEOUT 2.0f
#define POSITION_TOLERANCE 1.65f
#define POSITION_LOW_TOLERANCE 2.0f

//Line Follower States
typedef enum {
    OFF_ON_OFF, ON_ON_OFF, ON_OFF_OFF, OFF_ON_ON, OFF_OFF_ON, OFF_OFF_OFF, ON_ON_ON, ON_OFF_ON
} LineFollowerState;

/*
 * Task Constants
 */
#define MAX_COMMANDS 20

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
