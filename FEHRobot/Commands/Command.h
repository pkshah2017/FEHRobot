class Command
{
private:
    virtual int initialize() = 0;
    virtual int run() = 0;
    virtual bool isFinished() = 0;
public:
    Command();
	int execute();
};

