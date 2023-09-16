#include "shell.h"

int check_builtIn(char *arg)
{
	if (_strcmp(arg, "exit") == 0)
	{
		_puts("Exiting Shell");
		exit(0);
	}

	return (0);
}
