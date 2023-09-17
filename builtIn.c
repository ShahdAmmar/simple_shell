#include "shell.h"

/**
 * check_builtIn - fucntion to check if the command is bultin
 * @arg: the command to be checked
 * Return: 0 it is not buitin
 *		1 if is builtin
 */

int check_builtIn(char *arg)
{
	if (_strcmp(arg, "exit") == 0)
	{
		_puts("Exiting Shell");
		exit(0);
	}
	else if (_strcmp(arg, "env") == 0)
	{
		char **env = environ;

		while (*env != NULL)
		{
			_puts(*env);
			env++;
		}
	}

	return (0);
}
