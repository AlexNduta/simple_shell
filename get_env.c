#include "shell.h"

/**
* c_strdup - Custom string duplication; excludes beginning bytes.
* @str: String to duplicate (e.g., environmental variable PATH=/bin:/bin/ls).
* @cs: Number of bytes to exclude (e.g., excludes "PATH=").
* Return: Duplicated string (e.g., /bin:/bin/ls).
*/
char *c_strdup(char *str, int cs)
{
int len = strlen(str + cs);
char *duplicate_str = malloc(sizeof(char) * (len + 1));

if (duplicate_str == NULL)
return (NULL);

_strcpy(duplicate_str, str + cs);
return (duplicate_str);
}

/**
* get_env - gets and returns copy of the requested env variable.
* @str: String to store the requested environmental variable.
* @env: Linked list of environmental variables.
* Return: Copy of the requested environmental variable.
char *get_env(char *str, list_t *env)
{
while (env != NULL)
{
if (strncmp(env->var, str, strlen(str)) == 0 && env->var[strlen(str)] == '=')
break;
env = env->next;
}

return (c_strdup(env->var, strlen(str) + 1));
}
*/
char *get_env(char *str, list_t *env)
{
int j = 0, cs = 0;

while (env != NULL)
{
j = 0;
while ((env->var)[j] == str[j]) /* find desired env variable */
j++;
if (str[j] == '\0' && (env->var)[j] == '=')
break;
env = env->next;
}

while (str[cs] != '\0') /* find how many bytes in env variable title */
cs++;
cs++; /*counts 1 more for = sign*/
return (c_strdup(env->var, cs)); /* make a copy of variable w/o title */
}
