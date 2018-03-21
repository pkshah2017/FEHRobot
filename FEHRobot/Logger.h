#ifndef LOGGER
#define LOGGER

#include <FEHSD.h>
#include "Robot.h"

class Logger
{
private:
    Robot robot;
public:
    Logger(Robot &robot_);
    void logWorldState();
    void logMessage(const char *message);
    void logMessage(char *message);
    void printError(StatusCode errorCode);
};

extern Logger logger;

#endif
