#include "shell.h"

int main()
{
        char **array;
	pid_t pid;

        while (1)
        {
                if (INTERACTIVE)
                        prompt();
                array = getinput();

                pid = fork();
                if (pid == -1)
                {
                        perror("fork");
			free(array);
                        exit(EXIT_FAILURE);
                }
                else if (pid == 0)
                {
			int val = execve(array[0], array, NULL);
                        if (val == -1)
                        {
                                perror("excute");
				free(array);
                                exit(EXIT_FAILURE);
                        }
                }
                else
                {
                        wait(NULL);
                }
        }
        return (0);
}
