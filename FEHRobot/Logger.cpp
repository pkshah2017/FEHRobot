#include "Logger.h"
#include <FEHUtility.h>

void logMessage(const char *message){
    SD.Printf(message);
}

void logWorldState(Robot robot){
    SD.Printf("NEW DATA POINT\n");
    SD.Printf("TIME: %f\n", TimeNow());
    SD.Printf("ROBOT X: %f\n", robot.getX());
    SD.Printf("ROBOT Y: %f\n", robot.getY());
    SD.Printf("ROBOT HEADING: %f\n", robot.getHeading());
    SD.Printf("LEFT LIMIT STATE: %u\n", robot.getLimit(RobotLeft));
    SD.Printf("FRONT LIMIT STATE: %u\n", robot.getLimit(RobotFront));
    SD.Printf("RIGHT LIMIT STATE: %u\n", robot.getLimit(RobotRight));
    SD.Printf("LEFT OPTO VALUE: %f\n", robot.getOpto(LeftOpto));
    SD.Printf("CENTER OPTO VALUE: %f\n", robot.getOpto(CenterOpto));
    SD.Printf("RIGHT OPTO VALUE: %f\n", robot.getOpto(RightOpto));
    SD.Printf("DEADZONE STATUS: %d\n", robot.getDeadzoneStatus());
    SD.Printf("FUEL TYPE: %d\n", robot.getFuelType());
}
