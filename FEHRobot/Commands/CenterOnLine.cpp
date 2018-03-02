#include "CenterOnLine.h"
#include <FEHUtility.h>
#include <FEHLCD.h>

CenterOnLine::CenterOnLine(Robot &robot_)
{
    robot = robot_;
}

int CenterOnLine::initialize() {
    return 0;
}

int CenterOnLine::run() {
    //LCD.WriteLine("Running center on line");
    updateOptoStates();
    if(leftOptoStatus){
        robot.drive(90, 25);
        LCD.WriteRC("Move left ",4,1);
    } else if (rightOptoStatus){
        robot.drive(270, 25);
        LCD.WriteRC("Move right",4,1);
    } else{
        LCD.WriteRC("No Move   ",4,1);
    }

    return 0;
}

bool CenterOnLine::isFinished() {
    return centerOptoStatus && !leftOptoStatus && !rightOptoStatus;
}

int CenterOnLine::completion(){
    robot.stop();

    return 0;
}

bool CenterOnLine::checkLeftOpto(){
    LCD.WriteRC("Left Opto Value: ", 1, 1);
    LCD.WriteRC(robot.getOpto(LeftOpto), 1, 18);
    return robot.getOpto(LeftOpto) > 2.5;
}

bool CenterOnLine::checkCenterOpto(){
    LCD.WriteRC("Center Opto Value: ", 2, 1);
    LCD.WriteRC(robot.getOpto(CenterOpto), 2, 19);
    return robot.getOpto(CenterOpto) > 2.4;
}

bool CenterOnLine::checkRightOpto(){
    LCD.WriteRC("Right Opto Value: ", 3, 1);
    LCD.WriteRC(robot.getOpto(RightOpto), 3, 19);
    return robot.getOpto(RightOpto) > 2.25;
}

void CenterOnLine::updateOptoStates(){
    robot.updateSensorStates();
    leftOptoStatus = checkLeftOpto();
    centerOptoStatus = checkCenterOpto();
    rightOptoStatus = checkRightOpto();
}
