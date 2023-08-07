#include "shell.h"

/**
 * get_line - stores into malloce data into shell
 * @str: data buffer
 * Return: number of characters already read
 */
size_t get_line(char **str)
{
ssize_t read_size = 0, total_size = 0;
char buffer[1024];

while ((read_size = read(STDIN_FILENO, buffer, 1024 - 1)) > 0)
{
buffer[read_size] = '\0';
if (*str == NULL)
{
*str = _strdup(buffer);
total_size = read_size + 1;
}
else
{
*str = realloc(*str, total_size + read_size);
_strcat(*str, buffer);
total_size += read_size;
}
if (strchr(buffer, '\n') != NULL)
break;
}
return ((read_size == -1) ? -1 : total_size);
}
