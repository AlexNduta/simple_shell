#include "shell.h"
/**
* _cd - change directory
* @args: user's typed in command
* @env: enviromental linked list to retrieve HOME and OLDPWD paths
* @num: nth user command, to be used at error message
* Return: 0 if success 2 if failed
*/
int _cd(char **args, list_t *env, int num)
{
char *current_dir = NULL, *target_dir = NULL;
int exit_status = 0; /* The exit status of the cd command. */
current_dir = getcwd(NULL, 0);
if (args[1] != NULL)
{
if (args[1][0] == '~')
{
target_dir = get_env("HOME", env);
target_dir = c_strcat(target_dir, args[1]);
}
else if (args[1][0] == '-')
{
if (args[1][1] == '\0')
{
target_dir = get_env("OLDPWD", env);
}
}
else
{
if (args[1][0] != '/')
{
target_dir = getcwd(NULL, 0);
target_dir = _strcat(target_dir, "/");
target_dir = _strcat(target_dir, args[1]);
}
else
{
target_dir = _strdup(args[1]);
}
}
exit_status = cd_execute(env, current_dir, target_dir, args[1], num);
free(target_dir);
}
else
{
cd_only(env);
}
free_double_ptr(args);
free(current_dir);
return (exit_status);
}
