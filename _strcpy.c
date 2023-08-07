#include "shell.h"

/**
* get_length- it calculates the length of a string
* @str: parameter str which is a pointer to a character
* Return: it returns the length of the string which is
* to be calculated also it's an integer value.
*/
int get_length(char *str)
{
int length = 0;

while (str[length] != '\0')
{
length++;
}
return (length);
}
/**
* _strcpy - it duplicates a string from the source
* to destination and takes two parameters dest
* representing destination and src representing
* the source string.
* @dest: destination string
* @src: source string
* Return: a pointer to the destination buffer.
*/
char *_strcpy(char *dest, char *src)
{
int i;
int length = get_length(src);

for (i = 0; i <= length; i++)
{
dest[i] = src[i];
}
return (dest);
}
