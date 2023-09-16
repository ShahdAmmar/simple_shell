#include "shell.h"

char *ppath(const char *arg, const char *direc)
{
    char path[MAX_LETTERS];
    int p_len = 0;
    int arg_len = 0;

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

        if (access(arg, X_OK) != -1)
        {
                free(path_cp);
                return (arg);
        }

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
