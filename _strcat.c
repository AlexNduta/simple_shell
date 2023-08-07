#include "shell.h"

#include "shell.h"
/**
* _strcat - function which concatenates the source
* string src to the destination string
* dest.
* @dest: destination buffer
* @src: is the source string
* Return: returns a concatenated string
*/
char *_strcat(char *dest, char *src)
{
int dest_length = get_length(dest);
int src_length = get_length(src);
int total_length = dest_length + src_length;
int i;
int j;

dest = _realloc(dest, dest_length, sizeof(char) * total_length);

for (i = dest_length; i < total_length; i++)
{
dest[i] = src[j];
j++;
}
dest[total_length - 1] = '\0';

return (dest);
}
