#include "shell.h"

/**
* _which - fleshes out command by appending it to a matching PATH directory
* @str: first command user typed into shell (e.g. "ls" if user typed "ls -l")
* @env: environmental variable
* Return: a copy of fleshed out command (e.g. "/bin/ls" if originally "ls")
*/
char *_which(char *str, list_t *env)
{
char *path = get_env("PATH", env);
int i = 0;
char **dirs = c_str_tok(path, ":");

for (i = 0; dirs[i] != NULL; i++)
{
char *full_path = malloc(strlen(dirs[i]) + strlen(str) + 2);
strcpy(full_path, dirs[i]);
strcat(full_path, "/");
strcat(full_path, str);

if (access(full_path, F_OK) == 0)
{
free_double_ptr(dirs);
return (full_path);
}

free(full_path);
}

free_double_ptr(dirs);
return (str);
}


