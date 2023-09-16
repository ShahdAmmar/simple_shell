#include "shell.h"
#define MAX_PATH_LENGTH 1024

char *ppath(const char *arg, const char *direc)
{
    char path[MAX_PATH_LENGTH];
    int p_len = 0;
    int arg_len = 0;

    while (direc[p_len] != '\0' && p_len < MAX_PATH_LENGTH - 1)
    {
        path[p_len] = direc[p_len];
        p_len++;
    }
    path[p_len] = '/';
    p_len++;

    while (arg[arg_len] != '\0' && p_len < MAX_PATH_LENGTH - 1)
    {
        path[p_len] = arg[arg_len];
        p_len++;
        arg_len++;
    }
    path[p_len] = '\0';

    if (access(path, X_OK) != -1) {
	    char *ans = strdup(path);
        if (ans == NULL) {
            perror("strdup");
            exit(EXIT_FAILURE);
        }
        return ans;
    }
    return NULL;
}

char *get_path(char *arg)
{
        char *path_var = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin";
        char *path_cp = _strdup(path_var);
        char *direc = strtok(path_cp, ":");
        char *tot_path = NULL;

	while (direc != NULL)
    {
	char *temp_path = ppath(arg, direc);
        if (temp_path != NULL)
        {
            tot_path = strdup(temp_path);
            if (tot_path == NULL) {
                perror("strdup");
                exit(EXIT_FAILURE);
            }
            free(temp_path); 
            break;
        }
        direc = strtok(NULL, ":");
    }

    free(path_cp); 
    return tot_path;
}

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

                pid = fork();
                if (pid == -1)
                {
                        perror("fork");
			free(array);
                        exit(EXIT_FAILURE);
                }
                else if (pid == 0)
                {
			cmd = get_path(array[0]);
			if (cmd)
			 execve(cmd, array, env);
			else
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
		free(array);
        }
        return (0);
}
