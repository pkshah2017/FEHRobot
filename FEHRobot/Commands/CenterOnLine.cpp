#include "CenterOnLine.h"
#include <FEHUtility.h>
#include <FEHLCD.h>

CenterOnLine::CenterOnLine(Robot *robot_, int power_)
{
    power = power_;
    robot = robot_;
    isMovingLeft = true;
    numberOfReversals = 0;
}

StatusCode CenterOnLine::setup(int newPower){
    isMovingLeft = true;
    numberOfReversals = 0;
    power = newPower;
    return Success;
}

StatusCode CenterOnLine::initialize() {
    updateOptoStates();
    return Success;
}

StatusCode CenterOnLine::run() {
    StatusCode status = Success;
    updateOptoStates();
    if(leftOptoOnLine){
        (*robot).drive(90, power);
        if(!isMovingLeft){
            numberOfReversals++;
        }
        isMovingLeft = true;
    } else if (rightOptoOnLine){
        (*robot).drive(270, power);
        if(isMovingLeft){
            numberOfReversals++;
        }
        isMovingLeft = false;
    } else {
        (*robot).drive(90, power);
        if(!isMovingLeft){
            numberOfReversals++;
        }
        isMovingLeft = true;
    }

    return status;
}

bool CenterOnLine::isFinished() {

    return (centerOptoOnLine && !leftOptoOnLine && !rightOptoOnLine) || numberOfReversals > 5;
}

StatusCode CenterOnLine::completion(){
    (*robot).stop();

    return Success;
}

const char * CenterOnLine::getCommandName(){
    return "CenterOnLine";
}

bool CenterOnLine::checkLeftOpto(){
    LCD.WriteRC("Left Opto Value: ", 1, 1);
    LCD.WriteRC((*robot).getOpto(LeftOpto), 1, 18);
    return (*robot).getOpto(LeftOpto) > 2.35f;
}

bool CenterOnLine::checkCenterOpto(){
    LCD.WriteRC("Center Opto Value: ", 2, 1);
    LCD.WriteRC((*robot).getOpto(CenterOpto), 2, 19);
    return (*robot).getOpto(CenterOpto) > 1.85f;
}

bool CenterOnLine::checkRightOpto(){
    LCD.WriteRC("Right Opto Value: ", 3, 1);
    LCD.WriteRC((*robot).getOpto(RightOpto), 3, 19);
    return (*robot).getOpto(RightOpto) > 1.7f;
}

void CenterOnLine::updateOptoStates(){
    (*robot).updateSensorStates();
    leftOptoOnLine = checkLeftOpto();
    centerOptoOnLine = checkCenterOpto();
    rightOptoOnLine = checkRightOpto();
}
