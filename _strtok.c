#include "shell.h"

/**
* t_strlen - to calculate the length of a substring
* in the input string
* @str: a pointer to a character
* @pos: an integer
* @delm: a character that serves as delimeter
* Return: length of the substring
*/
int t_strlen(char *str, int pos, char delm)
{
int len = 0;

while ((str[pos] != delm) && (str[pos] != '\0'))
{
pos++;
len++;
}
return (len);
}

/**
* t_size - counts the occurrences of a delimeter
* character in the input string
* @str: pointer to a character array
* @delm: a character that serves as delimeter
* Return: the value of the num delm variable
*/
int t_size(char *str, char delm)
{
int i = 0, num_delm = 0;

while (str[i] != '\0')
{
if ((str[i] == delm) && (str[i + 1] != delm))
{
/* handle continuous delims */
num_delm++;
}
if ((str[i] == delm) && (str[i + 1] == '\0'))
{
/*handle continuous delims after full command */
num_delm--;
}
i++;
}
return (num_delm);
}

/**
* ignore_delm - ignores the first character of the input string
* if it matches the specified delimeter character
* @str: a pointer to a character array
* @delm: a character that serves as the delimeter
* Return: a new pointer
*/
char *ignore_delm(char *str, char delm)
{
while (*str == delm)
str++;
return (str);
}

