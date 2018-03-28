#include "CenterOnLine.h"
#include <FEHUtility.h>
#include <FEHLCD.h>

CenterOnLine::CenterOnLine(Robot *robot_)
{
    robot = robot_;
}

StatusCode CenterOnLine::initialize() {
    updateOptoStates();
    return Success;
}

StatusCode CenterOnLine::run() {
    StatusCode status = Success;
    updateOptoStates();
    if(leftOptoOnLine){
        (*robot).drive(90, 45);
    } else if (rightOptoOnLine){
        (*robot).drive(270, 45);
    } else if (!centerOptoOnLine){
        (*robot).drive(90, 45);
    }

    return status;
}

bool CenterOnLine::isFinished() {
    return centerOptoOnLine && !leftOptoOnLine && !rightOptoOnLine;
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
    return (*robot).getOpto(LeftOpto) > 2.5f;
}

bool CenterOnLine::checkCenterOpto(){
    LCD.WriteRC("Center Opto Value: ", 2, 1);
    LCD.WriteRC((*robot).getOpto(CenterOpto), 2, 19);
    return (*robot).getOpto(CenterOpto) > 2.2f;
}

bool CenterOnLine::checkRightOpto(){
    LCD.WriteRC("Right Opto Value: ", 3, 1);
    LCD.WriteRC((*robot).getOpto(RightOpto), 3, 19);
    return (*robot).getOpto(RightOpto) > 1.9f;
}

void CenterOnLine::updateOptoStates(){
    (*robot).updateSensorStates();
    leftOptoOnLine = checkLeftOpto();
    centerOptoOnLine = checkCenterOpto();
    rightOptoOnLine = checkRightOpto();
}
