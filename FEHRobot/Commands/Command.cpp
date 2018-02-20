#include "Command.h"
#include <FEHUtility.h>

#define REFRESH_RATE 20

Command::Command()
{
}

int Command::execute() {
	initialize();
	while (!isFinished()) {
		execute();
		Sleep(REFRESH_RATE);
	}
	return 0;
}
