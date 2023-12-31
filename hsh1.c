#include "shell.h"

/**
 * main - the entry point function for this shell
 * @argc: arg count
 * @argv: arg vector
 * Return: return 0 on success
 */

int main(int argc, char **argv)
{
	char **array, *cmd;
	pid_t pid;
	int c = 0, blt, val;
	(void)argc;

	while (1)
	{
		if (INTERACTIVE)
			prompt();
		array = getinput();
		if (array != NULL)
			c++;
		blt = check_builtIn(array);
		if (blt == 0)
		{
			free(array);
			continue;
		}
		cmd = get_path(array[0]);
		if (!cmd)
		{
			_printe(argv[0], c, array[0], "not found");
			free(array), free(cmd);
			continue;
		}
		pid = fork();
		if (pid == -1)
			perror("./hsh"), free(array), free(cmd), exit(0);
		else if (pid == 0)
		{
			val = execve(cmd, array, environ);
			if (val == -1)
				perror("./hsh"), free(array), free(cmd), exit(0);
		}
		else
			wait(NULL);
		free(array), free(cmd);
	}
	free(array), free(cmd);
	return (0);
}
