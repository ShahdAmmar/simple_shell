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
		ans = _strdup(path);
		if (ans == NULL)
		{
			perror("./hsh");
			free(ans);
			exit(0);
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
	char *p = getenv("$PATH");
	char *path_cp = _strdup(p);
	char *direc = strtok(path_cp, ":");
	char *tot_path = NULL;

	if (access(arg, X_OK) != -1)
	{
		free(path_cp);
		return (arg);
	}

	while (direc != NULL)
	{
		tot_path = ppath(arg, direc);
		if (tot_path == NULL)
			direc = strtok(NULL, ":");
		else
			break;
	}
	free(path_cp);
	return (tot_path);
}
