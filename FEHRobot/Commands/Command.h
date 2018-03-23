#ifndef COMMAND
#define COMMAND

#include "Constants.h"
#include "FEHLCD.h"

class Command
{
private:
    virtual StatusCode initialize() = 0;
    virtual StatusCode initializeFailureRecovery(StatusCode error);
    virtual StatusCode run() = 0;
    virtual StatusCode runFailureRecovery(StatusCode error);
    virtual bool isFinished() = 0;
    virtual StatusCode completion() = 0;

    StatusCode printError(StatusCode errorCode);
public:
    Command();
    StatusCode execute();

    virtual const char* getCommandName() = 0;
};

#endif
