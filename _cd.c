#include "shell.h"
/**
* c_strcat - com bines two strings ignoring the first character
* @dest: string to be combined with
* @src: string to combine
* Return: concatenated string
*/

char *c_strcat(char *dest, char *src)
{
int i, j;

/* find the length of the destination string */
for (i = 0; dest[i] != '\0'; i++)
/* find the length of the source string */
for (j = 0; src[j] != '\0'; j++)
/* allocate a new memory block for the destination string */
dest = realloc(dest, i + j + 1);
/* ignore the first character of the source string */
for (j = 1; src[j] != '\0'; j++)
dest[i + j - 1] = src[j];
/* terminate the destination string with a null character */
dest[i + j] = '\0';
return (dest);
}


/**
* c_setenv - custom _setenv by concatenating string first before setting
* @env: environmental variable linked list
* @name: environmental variable name (e.g. "OLDPWD")
* @dir: directory path (e.g. "/home/vagrant/directory1")
* Return: 0 on success (e.g. "OLDPWD=/home/vagrant/directory1")
*/
int c_setenv(list_t **env, char *name,  char *dir)
{
int index, j;
char *cat = NULL;
list_t *current = NULL;
/* Create a new string in the format "name=value" */
cat = malloc(strlen(name) + strlen(dir) + 2);
if (!cat)
{
return (-1);
}
sprintf(cat, "%s=%s", name, dir);

index = find_env(*env, name);
if (index == -1)
{
free(cat);
return (-1);
}

current = *env;
for (j = 0; j < index; j++)
{
if (!current)
{
free(cat);
return (-1);
}
current = current->next;
}
free(current->var);
current->var = strdup(cat);
free(cat);

return (0);
}
/**
* cd_only - change directory to home dir
* @env: bring in environmental linked list to update PATH and OLDPWD
*/

void cd_only(list_t *env)
{
char *current = getcwd(NULL, 0);
char *home = get_env("HOME", env);
char *new_current = NULL;

if (home != NULL)
{
c_setenv(&env, "OLDPWD", current);

if (access(home, F_OK) == 0)
{
chdir(home);
new_current = getcwd(NULL, 0); /* Get the new working directory */
c_setenv(&env, "PWD", new_current);
free(new_current); /* Free the memory for the new_current variable */
}

free(home);
free(current);
}
}
