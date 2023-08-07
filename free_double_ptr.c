#include "shell.h"
/**
* free_double_ptr - free malloced arrays
* @str: array of strings
*/
void free_double_ptr(char **str)
{
int i = 0;
for (i = 0; str[i] != NULL; i++)
{
free(str[i]);
}
free(str);
}
