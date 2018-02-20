class Command
{
public:
	Command();
	virtual int initialize() = 0;
	virtual int run() = 0;
	virtual bool isFinished() = 0;
	int execute();
};

