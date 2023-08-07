#include "shell.h"

/**
* check_digit - checks whether a character is
* numeric character or not.
* @c: character input
* Return: corresponding integer value
*/
int check_digit(char c)
{
return (c >= '0' && c <= '9');
}
/**
* c_atoi - converts the string argument to
* an integer
* @s: character pointer
* Return: the converted integer value
*/
int c_atoi(char *s)
{
int num = 0;
int i;

for (i = 0; s[i] != '\0'; i++)
{
if (!check_digit(s[i]))
{
return (-1);
}
num = num * 10 + (s[i] - '0');
}
return (num);
}
/**
* __exit - terminates the calling process
* @str: a pointer to a pointer character
* @env: a pointer to a linked list
* @num: an integer
* @command: pointer of character
* Return: an argument
*/
int __exit(char **str, list_t *env, int num, char **command)
{
int exit_value = 0;

if (str[1] != NULL)
{
exit_value = c_atoi(str[1]);
switch (exit_value)
{
case -1:
illegal_number(str[1], num, env);
free_double_ptr(str);
return (2);
default:
break;
}
}
free_double_ptr(str);
free_linked_list(env);
if (command != NULL)
{
free_double_ptr(command);
}
exit(exit_value);
}
