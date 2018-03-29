#include "Logger.h"
#include <FEHUtility.h>
#include <FEHLCD.h>
#include <string.h>
#include <stdio.h>

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
    int messageLength = strlen(message);

    char stringMessage[messageLength + 50];

    int ret = snprintf(stringMessage, sizeof stringMessage, "%f: %s\0",  TimeNow(), message);
    //SD.Printf(stringMessage);
    // SD.Printf(messageLength);
    //    SD.Printf(" ");
    SD.Printf(message);
    SD.Printf("\r\n");
}


void Logger::logMessageScreen(const char *message){
    LCD.WriteLine(message);
    SD.Printf(message);
    SD.Printf("\r\n");
}

void Logger::logMessage(char *message){
    SD.Printf(message);
    SD.Printf("\r\n");
}

void Logger::logWorldState(){
    SD.Printf("NEW DATA POINT\t");
    SD.Printf("TIME: %f\t", TimeNow());
    SD.Printf("ROBOT ACTUAL X: %f\t", (*robot).getCurrentX());
    SD.Printf("ROBOT ACTUAL Y: %f\t", (*robot).getCurrentY());
    SD.Printf("ROBOT ACTUAL HEADING: %f\t", (*robot).getCurrentHeading());
    SD.Printf("ROBOT X: %f\t", (*robot).getX());
    SD.Printf("ROBOT Y: %f\t", (*robot).getY());
    SD.Printf("ROBOT HEADING: %f\t", (*robot).getHeading());
    SD.Printf("LEFT LIMIT STATE: %u\t", (*robot).getLimit(RobotLeft));
    SD.Printf("FRONT LIMIT STATE: %u\t", (*robot).getLimit(RobotFront));
    SD.Printf("RIGHT LIMIT STATE: %u\t", (*robot).getLimit(RobotRight));
    SD.Printf("LEFT OPTO VALUE: %f\t", (*robot).getOpto(LeftOpto));
    SD.Printf("CENTER OPTO VALUE: %f\t", (*robot).getOpto(CenterOpto));
    SD.Printf("RIGHT OPTO VALUE: %f\t", (*robot).getOpto(RightOpto));
    SD.Printf("DEADZONE STATUS: %d\t", (*robot).getDeadzoneStatus());
    SD.Printf("FUEL TYPE: %d\t\r\n", (*robot).getFuelType());
}

void Logger::logError(StatusCode errorCode){

    SD.Printf("ERROR CODE: %u\r\n", (int)errorCode);
    SD.Printf("Description: ");
    SD.Printf((errordesc[(int)errorCode].message));
    SD.Printf("\r\n");
}
