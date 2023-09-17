#include "shell.h"
/**
 * main - the entry point function for this shell
 * Return: return 0 on success
 */
int main(void)
{
	char **array;
	pid_t pid;
	char *cmd;

	while (1)
	{
		if (INTERACTIVE)
			prompt();
		array = getinput();
		check_builtIn(array[0]);
		cmd = get_path(array[0]);
		if (!cmd)
		{
			_puts("command not found");
			free(array);
			free(cmd);
			continue;
		}
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			free(array);
			free(cmd);
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			int val = execve(cmd, array, NULL);

			if (val == -1)
			{
				perror("excute");
				free(array);
				free(cmd);
				exit(EXIT_FAILURE);
			}
		}
		else
			wait(NULL);
			free(array);
			free(cmd);
	}
	return (0);
}
