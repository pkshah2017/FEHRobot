#include "Commands/Command.h"
#include <vector>
#include <memory>

class Task
{
private:
    std::vector<std::unique_ptr<Command>> commandList;
public:
    Task();
	int execute();
    int addCommand(Command* command);
};

//TODO: Make a private struct to create a singly linked list of commands
//      Use the struct to form a linked list
//          Create an add function to add functions to the list
//      For Execute
//          while(next command exists and there hasnt been an error)
//              run command and store error code
//              if error run recovery function
//          return errorCode

//TODO: Create a programSet which is chosen in program chooser
