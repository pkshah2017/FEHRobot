#include "DriveTrain.h"
#include <math.h>
#include <FEHLCD.h>

DriveTrain::DriveTrain() :
    FRMotor(FEHMotor::Motor0, MOTOR_VOLTAGE),
    FLMotor(FEHMotor::Motor1, MOTOR_VOLTAGE),
    BLMotor(FEHMotor::Motor2, MOTOR_VOLTAGE),
    BRMotor(FEHMotor::Motor3, MOTOR_VOLTAGE)
{
}

int DriveTrain::driveAndTurn(int heading, int power, int turnSpeed){
    LCD.WriteLine("Driving and turning");
    float headingRad = heading * PI / 180;
    float powerPercent = power / 100.0;
    LCD.Write("Power Percent: ");
    LCD.WriteLine(powerPercent);
//heading is 45 degrees
    float calculatedCos = cos(headingRad + PI / 4);//0
    float calculatedSin = sin(headingRad + PI / 4);//1
    LCD.WriteLine("calculated cos and sin");

    float FRSpeed = powerPercent * calculatedSin + turnSpeed;
    float FLSpeed = powerPercent * calculatedCos - turnSpeed;
    float BRSpeed = powerPercent * calculatedCos + turnSpeed;
    float BLSpeed = powerPercent * calculatedSin - turnSpeed;
    LCD.WriteLine(FRSpeed);
    LCD.WriteLine(FLSpeed);
    LCD.WriteLine(BRSpeed);
    LCD.WriteLine(BLSpeed);
    LCD.WriteLine("Calculated Raw Power");


    float speeds[4];

    speeds[0] = FRSpeed;
    speeds[1] = FLSpeed;
    speeds[2] = BRSpeed;
    speeds[3] = BLSpeed;

    LCD.WriteLine("Created speeds array");

    float max = speeds[0];
    bool needsToRescale = max > 1;
    for(int i = 1; i < 4; i++){
        if(max < abs(speeds[i])){
            max = abs(speeds[i]);
        }
        if(max > 1){
            needsToRescale = true;
        }
    }

    LCD.WriteLine("Found max");

    if(needsToRescale){
        for(int i = 0; i < 4; i++){
            speeds[i] = speeds[i] / max;
            LCD.WriteLine(speeds[i]);
        }
    }

    LCD.WriteLine("Found final motor values");

    FRMotor.SetPercent(speeds[0] * 100);
    FLMotor.SetPercent(speeds[1] * 100);
    BRMotor.SetPercent(speeds[2] * 100);
    BLMotor.SetPercent(speeds[3] * 100);

    LCD.WriteLine("Set motor output");

    return 0;
}

int DriveTrain::drive(int heading, int power) {

    float x = cos((45 - heading)*PI / 180.0);
    float y = sin((45 - heading)*PI / 180.0);

    FRMotor.SetPercent(-x*power);
    FLMotor.SetPercent(y*power);
    BLMotor.SetPercent(x*power);
    BRMotor.SetPercent(-y*power);
/*
    driveAndTurn(heading, power, 0);
*/
    return 0;
}

int DriveTrain::stop() {
    FLMotor.Stop();
    FRMotor.Stop();
    BLMotor.Stop();
    BRMotor.Stop();

    return 0;
}
