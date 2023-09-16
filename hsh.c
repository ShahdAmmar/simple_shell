#include "shell.h"

int main()
{
        char **array;
	pid_t pid;
	char *cmd;
	char **env;

        while (1)
        {
                if (INTERACTIVE)
                        prompt();
                array = getinput();

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
			int val = execve(cmd, array, env);
			if (val == -1)
			{
				perror("excute");
				free(array);
				free(cmd);
				exit(EXIT_FAILURE);
			}			
		}
		else
		{
			wait(NULL);
		}
		
		free(array);
		free(cmd);
        }
        return (0);
}
