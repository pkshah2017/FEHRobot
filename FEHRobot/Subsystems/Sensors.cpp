#include "Sensors.h"
#include <FEHRPS.h>

Sensors::Sensors()
    : FrontLimit(FEHIO::P0_2),
      LeftLimit(FEHIO::P0_6),
      RightLimit(FEHIO::P0_4),
      cdsCell(FEHIO::P0_0),
      leftOpto(FEHIO::P1_4),
      centerOpto(FEHIO::P1_2),
      rightOpto(FEHIO::P1_0 )
{
    updateSensorStates();
}

int Sensors::updateSensorStates() {
    frontLimitState = FrontLimit.Value();
    leftLimitState = LeftLimit.Value();
    rightLimitState = RightLimit.Value();
    cdsState = cdsCell.Value();
    leftOptoState = leftOpto.Value();
    centerOptoState = centerOpto.Value();
    rightOptoState = rightOpto.Value();
}

bool Sensors::getFrontLimit() {
    return frontLimitState;
}

bool Sensors::getLeftLimit() {
    return leftLimitState;
}

bool Sensors::getRightLimit() {
    return rightLimitState;
}

float Sensors::getCDSState() {
    return cdsState;
}

float Sensors::getLeftOpto() {
    return leftOptoState;
}

float Sensors::getCenterOpto() {
    return centerOptoState;
}

float Sensors::getRightOpto() {
    return rightOptoState;
}

int Sensors::updateRPSState(){
    fuelType = RPS.FuelType();
    deadzoneStatus = RPS.IsDeadzoneActive();
    if(RPS.X() != -1.0f){
        robotX = RPS.X();
    }
    if(RPS.Y() != -1.0f){
        robotY = RPS.Y();
    }
    if(RPS.Heading() != -1.0f){
        robotHeading = RPS.Heading();
    }
}

int Sensors::getFuelType(){
    return fuelType;
}

int Sensors::isDeadzoneActive(){
    return deadzoneStatus;
}

float Sensors::getRobotX(){
    return robotX;
}

float Sensors::getRobotY(){
    return robotY;
}

float Sensors::getRobotHeading(){
    return robotHeading;
}
