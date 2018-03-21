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

int DriveTrain::driveAndTurn(int heading, int power, float turnSpeed){
    LCD.WriteRC("Driving and turning", 1, 1);


    float x = cos((45 - heading)*PI / 180.0);
    float y = sin((45 - heading)*PI / 180.0);


    //float headingRad = heading * PI / 180;
    float powerPercent = (float)power;
//    LCD.WriteRC("Power Percent: ", 2, 1);
//    LCD.WriteRC(powerPercent, 2, 16);
//heading is 45 degrees
    //float calculatedCos = cos(headingRad + PI / 4);//0
   // float calculatedSin = sin(headingRad + PI / 4);//1
   // LCD.WriteLine("calculated cos and sin");

    float FRSpeed = powerPercent * -x + turnSpeed;
    float FLSpeed = powerPercent * y + turnSpeed;
    float BRSpeed = powerPercent * -y + turnSpeed;
    float BLSpeed = powerPercent * x + turnSpeed;

//    LCD.WriteRC("Raw Powers: ", 3, 1);
//    LCD.WriteRC(FRSpeed, 3, 12);
//    LCD.WriteRC(FLSpeed, 4, 12);
//    LCD.WriteRC(BRSpeed, 5, 12);
//    LCD.WriteRC(BLSpeed, 6, 12);


    float speeds[4];

    speeds[0] = FRSpeed;
    speeds[1] = FLSpeed;
    speeds[2] = BRSpeed;
    speeds[3] = BLSpeed;

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

//    LCD.WriteRC("Scaled Powers: ", 7, 1);
//    if(needsToRescale){
//        for(int i = 0; i < 4; i++){
//            speeds[i] = speeds[i] / max;
//            LCD.WriteRC(FRSpeed, 8 + i, 12);
//        }
//    }

  //  LCD.WriteLine("Found final motor values");

    FRMotor.SetPercent(speeds[0]);
    FLMotor.SetPercent(speeds[1]);
    BRMotor.SetPercent(speeds[2]);
    BLMotor.SetPercent(speeds[3]);

    //LCD.WriteLine("Set motor output");

    return 0;
}

int DriveTrain::turn(int power) {
    FRMotor.SetPercent(power);
    FLMotor.SetPercent(power);
    BLMotor.SetPercent(power);
    BRMotor.SetPercent(power);

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
