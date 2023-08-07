#include "shell.h"
/**
* cd_execute - executes the cd
* @env: bring in environmental linked list to update PATH and OLDPWD
* @current: bring in current working directotry
* @dir: bring in directory path to change to
* @str: bring in the 1st argument to write out error
* @num: bring in the line number to write out error
* Return: 0 if success 2 if fail
*/

int cd_execute(list_t *env, char *current, char *dir, char *str, int num)
{
int i = 0;
char *cmd_and_args[4];
char *cmd_and_args2[4];

if (access(dir, F_OK) == 0)
{
/* Save the current working directory */
cmd_and_args[0] = "setenv";
cmd_and_args[1] = "OLDPWD";
cmd_and_args[2] = current;
cmd_and_args[3] = NULL;
_setenv(&env, cmd_and_args);

/* Change to the directory */
if (chdir(dir) == 0)
{
/* Get the current working directory */
free(current); /* Free the old current as getcwd allocates memory */
current = getcwd(NULL, 0);
cmd_and_args2[0] = "setenv";
cmd_and_args2[1] = "PWD";
cmd_and_args2[2] = current;
cmd_and_args2[3] = NULL;
_setenv(&env, cmd_and_args2);
}
else
{
i = 2;
cant_cd_to(str, num, env);
}
}
else
{
i = 2;
cant_cd_to(str, num, env);
}

free(current);
return (i);
}

