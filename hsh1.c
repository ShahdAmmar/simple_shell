#include "shell.h"

/**
 * main - the entry point function for this shell
 * Return: return 0 on success
 */
int main(void)
{
	char **array, *cmd;
	pid_t pid;

	while (1)
	{
		if (INTERACTIVE)
			prompt();
		array = getinput();
		check_builtIn(array[0]);
		cmd = get_path(array[0]);
		if (!cmd)
		{
			/*_puts("./hsh: command not found");*/
			perror("./hsh");
			free(array), free(cmd);
			continue;
		}
		pid = fork();
		if (pid == -1)
		{
			perror("./hsh");
			free(array), free(cmd);
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			int val = execve(cmd, array, NULL);

			if (val == -1)
			{
				perror("./hsh");
				free(array), free(cmd);
				exit(EXIT_FAILURE);
			}
		}
		else
			wait(NULL);
		free(array), free(cmd);
	}
	return (0);
}
