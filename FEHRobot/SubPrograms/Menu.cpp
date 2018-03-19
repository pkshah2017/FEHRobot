#include "Menu.h"
#include <FEHRPS.h>
#include "FEHLCD.h"
#include "FEHBattery.h"

#define MAIN_MENU 0
#define RUN_ALL 1
#define TESTING_MENU 2
#define DIAGNOSTIC 3
#define RPS_CHECK 4
#define SYSTEM_CHECK 5
#define OPTO_CHECK 6

#define BUTTONS_TASK 0
#define JACK_TASK 1
#define WRENCH_TASK 2
#define CRANK_TASK 3

#define MENU_COLOR WHITE
#define TEXT_COLOR GOLD
#define DARK_TEXT_COLOR BLACK
#define HIGH_COLOR LIGHTBLUE
#define ERROR_COLOR RED
#define SUCCESS_COLOR GREEN
#define HEADER_COLOR BLUE
#define DIAGNOSTIC_BACK_COLOR WHITE


Menu::Menu(Robot &robot_)
    :buttons(robot_),
      jack(robot_),
      wrench(robot_),
      crank(robot_)
{

}

int  Menu::mainMenu()
{
    LCD.Clear(BLACK);
    LCD.SetFontColor(WHITE);
    LCD.SetBackgroundColor(WHITE);
    LCD.FillRectangle(1,1,319,39);
    FEHIcon::Icon mainHeader[1];
    char mainHeaderlabel[1][20] = {"Team G7!"};
    FEHIcon::DrawIconArray(mainHeader, 1, 1, 1, 201, 1, 1, mainHeaderlabel, MENU_COLOR, HEADER_COLOR);
    mainHeader[0].Select();
    LCD.SetBackgroundColor(BLACK);

    FEHIcon::Icon mainMenu[3];
    char mainLabels[3][20] = {"Run All","Testing","Diagnostic"};
    FEHIcon::DrawIconArray(mainMenu, 3, 1, 40, 30, 1, 1, mainLabels, MENU_COLOR, TEXT_COLOR);
    LCD.SetFontColor(TEXT_COLOR);
    LCD.WriteAt("BATT:        V", 0, 222);
    LCD.SetFontColor(SUCCESS_COLOR);
    int currentMenu=MAIN_MENU, n;
    float x, y;
    float b = 0, batteryVoltage = 0;

    while(currentMenu==MAIN_MENU)
    {
        /* Display average battery voltage to screen */
        batteryVoltage = ((batteryVoltage*b)+Battery.Voltage());
        batteryVoltage = batteryVoltage/(++b);
        LCD.WriteAt(batteryVoltage, 72, 222);
        if (LCD.Touch(&x, &y))
        {
            /* Check to see if a main menu icon has been touched */
            for (n=0; n<=2; n++)
            {
                if (mainMenu[n].Pressed(x, y, 0))
                {
                    currentMenu = n+1;
                    mainMenu[n].WhilePressed(x, y);
                    break;
                }
            }
        }
    }
    return currentMenu;
}

void  Menu::booltoIcon(FEHIcon::Icon inputIcon, int input)
{
    if (input)
    {
        inputIcon.ChangeLabelString("True");
    }
    else
    {
        inputIcon.ChangeLabelString("False");
    }
}
void  Menu::updateIcon(FEHIcon::Icon inputIcon, float input)
{

    inputIcon.ChangeLabelFloat(input);

}

int  Menu::runAll()
{
    LCD.Clear(BLACK);
    int currentMenu;


    buttons.execute();
    jack.execute();
    wrench.execute();
    crank.execute();

    currentMenu = MAIN_MENU;
    return currentMenu;
}

int  Menu::testingMenu()
{
    LCD.Clear(BLACK);

    /* Create icons for DC motors menu */
    FEHIcon::Icon testingHeading[1];
    char testingHeaderlabel[1][20] = {"Testing"};
    FEHIcon::DrawIconArray(testingHeading, 1, 1, 1, 201, 1, 1, testingHeaderlabel, MENU_COLOR, TEXT_COLOR);

    FEHIcon::Icon Back[1];
    char backLabel[1][20] = {"<-"};
    FEHIcon::DrawIconArray(Back, 1, 1, 1, 201, 1, 260, backLabel, MENU_COLOR, TEXT_COLOR);

    FEHIcon::Icon testingMenu[4];
    char testingLabels[4][20] = {"Buttons","Jack","Wrench","Crank"};
    FEHIcon::DrawIconArray(testingMenu, 4, 1, 40, 1, 1, 1, testingLabels, MENU_COLOR, TEXT_COLOR);

    int currentMenu=TESTING_MENU, runTask =-1,n =-1;
    float x, y;
    while(currentMenu==TESTING_MENU)
    {
        if (LCD.Touch(&x, &y))
        {
            for (n=0; n<=3; n++)
            {
                if (testingMenu[n].Pressed(x, y, 0))
                {
                    runTask = n;
                    testingMenu[n].WhilePressed(x, y);
                    break;
                }
            }
            switch (runTask)
            {
            case BUTTONS_TASK:
                LCD.Clear(BLACK);
                LCD.WriteLine("EXECUTE");
                buttons.execute();
                currentMenu = MAIN_MENU;
                break;
            case JACK_TASK:
                LCD.Clear(BLACK);
                LCD.WriteLine("EXECUTE");
                jack.execute();
                currentMenu = MAIN_MENU;
                break;
            case WRENCH_TASK:
                wrench.execute();
                currentMenu = MAIN_MENU;
                break;
            case CRANK_TASK:
                crank.execute();
                currentMenu = MAIN_MENU;
                break;
            }
        }
        /* If back button has been touched, go to main menu */
        if (Back[0].Pressed(x, y, 0))
        {
            Back[0].WhilePressed(x, y);
            currentMenu = MAIN_MENU;
        }
    }
    return currentMenu;
}

int  Menu::diagnosticMenu(){
    LCD.Clear(BLACK);
    float x,y;
    int currentMenu=DIAGNOSTIC;

    FEHIcon::Icon testingHeading[1];
    char testingHeaderLabel[1][20] = {"Testing"};
    FEHIcon::DrawIconArray(testingHeading, 1, 1, 1, 201, 1, 1, testingHeaderLabel, MENU_COLOR, TEXT_COLOR);

    FEHIcon::Icon diagnosticMenu[3];
    char diagnosticLabels[3][20] = {"System Check","RPS Check","Opto Check"};
    FEHIcon::DrawIconArray(diagnosticMenu, 3, 1, 40, 30, 1, 1,diagnosticLabels, MENU_COLOR, TEXT_COLOR);

    FEHIcon::Icon Back[1];
    char backLabel[1][20] = {"<-"};
    FEHIcon::DrawIconArray(Back, 1, 1, 1, 201, 1, 260, backLabel, MENU_COLOR, TEXT_COLOR);

    while(currentMenu==DIAGNOSTIC)
    {
        if (LCD.Touch(&x, &y))
        {
            if (diagnosticMenu[0].Pressed(x, y, 0))
            {
                currentMenu = SYSTEM_CHECK;
            }
            if (diagnosticMenu[1].Pressed(x, y, 0))
            {
                currentMenu = RPS_CHECK;
            }
            if (diagnosticMenu[2].Pressed(x, y, 0))
            {
                currentMenu = OPTO_CHECK;
            }
        }
        /* If back button has been touched, go to main menu */
        if (Back[0].Pressed(x, y, 0))
        {
            Back[0].WhilePressed(x, y);
            currentMenu = MAIN_MENU;
        }
    }
    return currentMenu;
}
int  Menu::RPSCheck(){
    int currentMenu=RPS_CHECK;
    LCD.Clear(BLACK);
    float x,y;
    FEHIcon::Icon testingHeading[1];
    char testingHeaderlabel[1][20] = {"RPS Check"};
    FEHIcon::DrawIconArray(testingHeading, 1, 1, 1, 201, 1, 1, testingHeaderlabel, MENU_COLOR, TEXT_COLOR);

    FEHIcon::Icon Backbtn[1];
    char backLabel[1][20] = {"<-"};
    FEHIcon::DrawIconArray(Backbtn, 1, 1, 1, 201, 1, 260, backLabel, MENU_COLOR, TEXT_COLOR);
    while(currentMenu==RPS_CHECK)
    {
        LCD.Touch(&x,&y);
        robot_.updateRPSStates();
        LCD.WriteRC("RPS X: ", 5, 1);
        LCD.WriteRC(robot_.getX(), 5, 19);
        LCD.WriteRC("RPS Y:  ", 7, 1);
        LCD.WriteRC(robot_.getY(), 7, 19);
        LCD.WriteRC("RPS Heading:  ", 9, 1);
        LCD.WriteRC(robot_.getHeading(), 9, 20);
        Sleep(REFRESH_RATE);
        if (Backbtn[0].Pressed(x, y, 0))
        {
            Backbtn[0].WhilePressed(x, y);
            currentMenu = DIAGNOSTIC;
            LCD.WriteRC("RPS OUT ", 7, 1);
        }
    }
    return currentMenu;
}
void  Menu::clearSystemCheck(){
    LCD.SetFontColor(BLACK);
    LCD.FillRectangle(0,200,319,119);
    LCD.SetFontColor(TEXT_COLOR);
}
int  Menu::systemCheck(){
    //successCount describes the total number of successful tests
    //it will actually be useful if I implement a timeout function
    int currentMenu=SYSTEM_CHECK, currentCheck =0,successCount =0;
    float x,y;

    LCD.Clear(BLACK);
    LCD.SetFontColor(TEXT_COLOR);

    FEHIcon::Icon testingHeading[1];
    char testingHeaderlabel[1][20] = {"System Check"};
    FEHIcon::DrawIconArray(testingHeading, 1, 1, 1, 199, 1, 1, testingHeaderlabel, MENU_COLOR, TEXT_COLOR);

    FEHIcon::Icon microSwitch[6];
    char microSwitchLabels[6][20] = {"Left", "Rear", "Right", " ", " ", " "};
    FEHIcon::DrawIconArray(microSwitch, 2, 3, 41,159, 1, 1, microSwitchLabels, MENU_COLOR, TEXT_COLOR);

    FEHIcon::Icon optoSensors[6];
    char optoSensorLabels[6][20] = {"Left", "Center", "Right", " ", " ", " "};
    FEHIcon::DrawIconArray(optoSensors, 2, 3, 81,119, 1, 1, optoSensorLabels, MENU_COLOR, TEXT_COLOR);

    FEHIcon::Icon rps[6];
    char rpsLabels[6][20] = {"X", "Y", "Heading", " ", " ", " "};
    FEHIcon::DrawIconArray(rps, 2, 3, 121,79, 1, 1, rpsLabels, MENU_COLOR, TEXT_COLOR);

    FEHIcon::Icon cdsSensor[2];
    char cdsSensorLabels[2][20] = {"cds"," "};
    FEHIcon::DrawIconArray(cdsSensor, 1, 2, 161,59, 1, 1, cdsSensorLabels, MENU_COLOR, TEXT_COLOR);

    FEHIcon::Icon Back[1];
    char backLabel[1][20] = {"<-"};
    FEHIcon::DrawIconArray(Back, 1, 1, 1, 199, 1, 260, backLabel, MENU_COLOR, TEXT_COLOR);

    while(currentMenu==SYSTEM_CHECK)
    {
        robot_.updateSensorStates();
        booltoIcon(microSwitch[3],robot_.getLimit(RobotLeft));
        booltoIcon(microSwitch[4],robot_.getLimit(RobotFront));
        booltoIcon(microSwitch[5],robot_.getLimit(RobotRight));

        updateIcon(optoSensors[3],robot_.getOpto(LeftOpto));
        updateIcon(optoSensors[4],robot_.getOpto(CenterOpto));
        updateIcon(optoSensors[5],robot_.getOpto(RightOpto));

        updateIcon(rps[3],robot_.getX());
        updateIcon(rps[4],robot_.getY());
        updateIcon(rps[5],robot_.getHeading());
        updateIcon(cdsSensor[1],robot_.getCDSState());

        clearSystemCheck();
        LCD.Touch(&x,&y);
        Sleep(REFRESH_RATE);
        if (Back[0].Pressed(x, y, 0))
        {
            Back[0].WhilePressed(x, y);
            currentMenu = DIAGNOSTIC;
        }
        switch(currentCheck){
        case 0:
            LCD.WriteRC("Push rear button ",13,1);
            if(!robot_.getLimit(RobotFront)){
                LCD.SetFontColor(SUCCESS_COLOR);
                LCD.WriteRC("Good!",13, 20);
                Sleep(500);
                currentCheck++;
                successCount++;
            }
            break;
        case 1:
            LCD.WriteRC("Push left button ",13,1);
            if(!robot_.getLimit(RobotLeft)){
                LCD.SetFontColor(SUCCESS_COLOR);
                LCD.WriteRC("Good!",13,20);
                Sleep(500);
                currentCheck++;
                successCount++;
            }
            break;
        case 2:
            LCD.WriteRC("Push right button ",13,1);
            if(!robot_.getLimit(RobotRight)){
                LCD.SetFontColor(SUCCESS_COLOR);
                LCD.WriteRC("Good!",13, 20);
                Sleep(500);
                currentCheck++;
                successCount++;
            }
            break;
        case 3:
            LCD.WriteRC("cds test",13,1);
            if(robot_.getCDSState()<2.8)
            {
                LCD.SetFontColor(SUCCESS_COLOR);
                LCD.WriteRC("Good!",13, 20);
                currentCheck++;
                successCount++;
            }
            break;
        case 4:
            LCD.WriteRC("Press Test Servo ",13,1);
            if(LCD.Touch(&x,&y))
            {
                robot_.setArmPosition(ArmUp);
                currentCheck++;
            }
            break;
        case 5:
            LCD.WriteRC("Did it work? ",13,1);
            LCD.Touch(&x,&y);
            if(y>219)
            {
                LCD.SetFontColor(SUCCESS_COLOR);
                LCD.WriteRC("Good!",13, 20);
                Sleep(500);
                currentCheck++;
                successCount++;
            }
            break;
        case 6:
            LCD.WriteRC("Press Test Motor ",13,1);
            if(LCD.Touch(&x,&y))
            {
                //                    DriveForTime d(robot_,0,50,1500);
                //                    d.execute();
                //                    d.changeHeading(90);
                //                    d.execute();
                //                    d.changeHeading(180);
                //                    d.execute();
                //                    d.changeHeading(270);
                //                    d.execute();
                currentCheck++;
            }
            break;
        case 7:
            LCD.WriteRC("Did it work ? ",13,1);
            LCD.Touch(&x,&y);
            if(y>219)
            {
                LCD.SetFontColor(SUCCESS_COLOR);
                LCD.WriteRC("Good!",13, 20);
                Sleep(500);
                currentCheck++;
                successCount++;
            }
            break;
        }
    }
    return currentMenu;
}

int  Menu::optoCheck(){
    int currentMenu=OPTO_CHECK;
    LCD.Clear(BLACK);
    float x,y;

    FEHIcon::Icon testingHeading[1];
    char testingHeaderlabel[1][20] = {"Opto Check"};
    FEHIcon::DrawIconArray(testingHeading, 1, 1, 1, 201, 1, 1, testingHeaderlabel, MENU_COLOR, TEXT_COLOR);

    FEHIcon::Icon Back[1];
    char backLabel[1][20] = {"<-"};
    FEHIcon::DrawIconArray(Back, 1, 1, 1, 201, 1, 260, backLabel, MENU_COLOR, TEXT_COLOR);
    while(currentMenu==OPTO_CHECK)
    {
        LCD.Touch(&x,&y);
        robot_.updateSensorStates();
        LCD.WriteRC("Left Opto:  ", 5, 1);
        LCD.WriteRC(robot_.getOpto(LeftOpto), 5, 19);
        LCD.WriteRC("Center Opto:  ", 7, 1);
        LCD.WriteRC(robot_.getOpto(CenterOpto), 7, 19);
        LCD.WriteRC("Right Opto :  ", 9, 1);
        LCD.WriteRC(robot_.getOpto(RightOpto), 9, 20);
        Sleep(REFRESH_RATE);

        if (Back[0].Pressed(x, y, 0))
        {
            Back[0].WhilePressed(x, y);
            currentMenu = DIAGNOSTIC;
        }
    }
    return currentMenu;
}

void Menu::ChooseOption()
{
    int currentMenu=MAIN_MENU;
    //RPS.InitializeTouchMenu();
    while (true)
    {
        switch (currentMenu)
        {
        case MAIN_MENU:
            currentMenu = mainMenu();
            break;
        case RUN_ALL:
            currentMenu = runAll();
            break;
        case TESTING_MENU:
            currentMenu = testingMenu();
            break;
        case DIAGNOSTIC:
            currentMenu = diagnosticMenu();
            break;
        case RPS_CHECK:
            currentMenu = RPSCheck();
            break;
        case SYSTEM_CHECK:
            currentMenu = systemCheck();
            break;
        case OPTO_CHECK:
            currentMenu = optoCheck();
            break;
        }
    }
}
