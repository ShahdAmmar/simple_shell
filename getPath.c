#include "shell.h"

/**
 * ppath - construct path and ensure excutable file exit
 * @arg: command entered by user
 * @direc: directory from $PATH
 * Return: path or NULL
 */
char *ppath(const char *arg, const char *direc)
{
	int p_len = 0, arg_len = 0;
	char path[MAX_LETTERS];
	char *ans;

	while (direc[p_len] != '\0' && p_len < MAX_LETTERS - 1)
	{
		path[p_len] = direc[p_len];
		p_len++;
	}
	path[p_len] = '/';
	p_len++;

	while (arg[arg_len] != '\0' && p_len < MAX_LETTERS - 1)
	{
		path[p_len] = arg[arg_len];
		p_len++;
		arg_len++;
	}
	path[p_len] = '\0';

	if (access(path, X_OK) != -1)
	{
		ans = strdup(path);
		if (ans == NULL)
		{
			perror("./hsh");
			/*exit(EXIT_FAILURE);*/
		}
		return (ans);
	}
	return (NULL);
}

/**
 * get_path - decide to construct a path for the command or not
 * @arg: command entered by user
 * Return: arg or constructed path
 */
char *get_path(char *arg)
{
	char *p = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin";
	char *path_cp = _strdup(p);
	char *direc = strtok(path_cp, ":");
	char *tot_path = NULL;
	char *temp_path;

	if (access(arg, X_OK) != -1)
	{
		free(path_cp);
		return (arg);
	}

	while (direc != NULL)
	{
		temp_path = ppath(arg, direc);
		if (temp_path != NULL)
		{
			tot_path = strdup(temp_path);
			if (tot_path == NULL)
			{
				perror("./hsh");
				/*exit(EXIT_FAILURE);*/
			}
			free(temp_path);
			break;
		}
		direc = strtok(NULL, ":");
	}
	free(path_cp);
	return (tot_path);
}
