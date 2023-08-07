#include "shell.h"
/**
 *_strdup- returns a pointer to  a new memory space
 *@str: string to duplicate
 *Return: pointer to a duplicated string
 */
char *_strdup(char *str)
{
char *duplicate_str;
size_t len = strlen(str) + 1; /* add 1 for the null terminator */

duplicate_str = malloc(len);
if (duplicate_str == NULL)
{
return (NULL);
}

memcpy(duplicate_str, str, len);

return (duplicate_str);
}

