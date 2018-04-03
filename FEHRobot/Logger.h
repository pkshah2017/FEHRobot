#ifndef LOGGER
#define LOGGER

#include <FEHSD.h>
#include "Robot.h"

class Logger
{
private:
    Robot *robot;

    float runStartTime;
public:
    Logger(Robot *robot_);
    void logWorldState();
    void logMessage(const char *message);
    void logMessage(char *message);
    void logMessageScreen(const char *message);
    void logError(StatusCode errorCode);

    void resetRunStartTime();
};

extern Logger *logger;

#endif
