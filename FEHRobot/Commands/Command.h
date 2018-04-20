/*
 * This command class is an abstract class used as a foundation for all the other commands. 
 * By creating a subclass from Command, the subclass only has to override 5 function to build a new command.
 * Additionally, the corresponding failure recovery methods can be overriden to allow for revocery from certain failures. 
 * 
 * Initalize
 *      The initialize function is run before any other function in the command.
 * Run
 *      The run function is run every 20 ms. This should be used to update any robot values 
 *      as the command is running.
 * isFinished
 *      This method returns a boolean which will be true when the command has finished and true otherwise. 
 * completion
 *      The completion method is run after the command is finished
 *  
*/
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
    virtual StatusCode completionFailureRecovery(StatusCode error);

    StatusCode printError(StatusCode errorCode);
public:
    Command();
    StatusCode execute();

    virtual const char* getCommandName() = 0;
};

#endif
