#include "Robot.h"
#include <FEHUtility.h>

Robot::Robot()
{
}

int Robot::updateSensorStates() {
    return sensors.updateSensorStates();
}

int Robot::updateRPSStates() {
    return sensors.updateRPSState();
}

bool Robot::getLimit(Direction direction) {
    bool result = false;
    switch(direction){
    case RobotFront:
        result = sensors.getFrontLimit();
        break;
    case RobotLeft:
        result = sensors.getLeftLimit();
        break;
    case RobotRight:
        result = sensors.getRightLimit();
        break;
    }

    return result;
}

float Robot::getOpto(OptoSelection optoSelection) {
    float result = -1;
    switch(optoSelection){
    case LeftOpto:
        result = sensors.getLeftOpto();
        break;
    case CenterOpto:
        result = sensors.getCenterOpto();
        break;
    case RightOpto:
        result = sensors.getRightOpto();
        break;
    }

    return result;
}

float Robot::getCDSState(){
    return sensors.getCDSState();
}

float Robot::getX(){
    return sensors.getRobotX();
}

float Robot::getY(){
    return sensors.getRobotY();
}

float Robot::getHeading(){
    return sensors.getRobotHeading();
}

int Robot::getFuelType(){
    return sensors.getFuelType();
}

int Robot::getDeadzoneStatus(){
    return sensors.isDeadzoneActive();
}

float Robot::getCurrentX(){
    return RPS.X();
}

float Robot::getCurrentY(){
    return RPS.Y();
}

float Robot::getCurrentHeading(){
    return RPS.Heading();
}

int Robot::turn(int power) {
    driveTrain.turn(power);

    return 0;
}

int Robot::drive(int heading, int power) {
    driveTrain.drive(heading, power);

    return 0;
}

int Robot::driveAndTurn(int heading, int power, int turnSpeed) {
    driveTrain.driveAndTurn(heading, power, turnSpeed);

    return 0;
}

int Robot::stop() {
    driveTrain.stop();

    return 0;
}

int Robot::setArmPosition(ArmPosition armPosition){
    arm.setArmPosition(armPosition);
}

int Robot::setCrankArmPosition(ArmPosition armPosition){
    crankArm.setArmPosition(armPosition);
}

void Robot::setLocation(LocationName locationName, float x, float y){
    rpsLocations.setLocation(locationName, x, y);
}

void Robot::setLocation(LocationName locationName, Position position){
    rpsLocations.setLocation(locationName, position);
}

float Robot::getLocationX(LocationName locationName, Course courseName){
    return rpsLocations.getLocationX(locationName, courseName);
}

float Robot::getLocationY(LocationName locationName, Course courseName){
    return rpsLocations.getLocationY(locationName, courseName);
}

Position Robot::getLocationPosition(LocationName locationName, Course courseName){
    return rpsLocations.getLocationPosition(locationName, courseName);
}

float Robot::getLocationX(LocationName locationName){
    return rpsLocations.getLocationX(locationName);
}

float Robot::getLocationY(LocationName locationName){
    return rpsLocations.getLocationY(locationName);
}

Position Robot::getLocationPosition(LocationName locationName) {
    return rpsLocations.getLocationPosition(locationName);
}
