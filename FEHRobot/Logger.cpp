#include "Logger.h"
#include <FEHUtility.h>

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

Logger::Logger(Robot *robot_){
    robot = robot_;
}

void Logger::logMessage(const char *message){
    SD.Printf(message);
}

void Logger::logMessage(char *message){
    SD.Printf(message);
}

void Logger::logWorldState(){
    SD.Printf("NEW DATA POINT\n");
    SD.Printf("TIME: %f\n", TimeNow());
    SD.Printf("ROBOT X: %f\n", (*robot).getX());
    SD.Printf("ROBOT Y: %f\n", (*robot).getY());
    SD.Printf("ROBOT HEADING: %f\n", (*robot).getHeading());
    SD.Printf("LEFT LIMIT STATE: %u\n", (*robot).getLimit(RobotLeft));
    SD.Printf("FRONT LIMIT STATE: %u\n", (*robot).getLimit(RobotFront));
    SD.Printf("RIGHT LIMIT STATE: %u\n", (*robot).getLimit(RobotRight));
    SD.Printf("LEFT OPTO VALUE: %f\n", (*robot).getOpto(LeftOpto));
    SD.Printf("CENTER OPTO VALUE: %f\n", (*robot).getOpto(CenterOpto));
    SD.Printf("RIGHT OPTO VALUE: %f\n", (*robot).getOpto(RightOpto));
    SD.Printf("DEADZONE STATUS: %d\n", (*robot).getDeadzoneStatus());
    SD.Printf("FUEL TYPE: %d\n", (*robot).getFuelType());
}

void Logger::printError(StatusCode errorCode){

    SD.Printf("ERROR CODE: %u\n", (int)errorCode);
    SD.Printf("Description: ");
    SD.Printf((errordesc[(int)errorCode].message));
    SD.Printf("\n");
}
