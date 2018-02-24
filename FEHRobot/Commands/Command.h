#ifndef COMMAND
#define COMMAND

class Command
{
private:
    virtual int initialize() = 0;
    virtual int initializeFailureRecovery(int error);
    virtual int run() = 0;
    virtual int runFailureRecovery(int error);
    virtual bool isFinished() = 0;
public:
    Command();
	int execute();
};

#endif
