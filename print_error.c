#include "shell.h"

/**
* not_found - write error ("sh: 1: lss: not found")
* @str: user's typed command
* @c_n: nth user's typed command
* @env: bring in environmental variables linked list to write shell name
*/

void not_found(char *str, int c_n, list_t *env)
{
char *shell = get_env("_", env); /* Get shell name to write */
int count = strlen(shell);
char num[12]; /*Assuming inn_to_string returns a max of 11 characters + '\0' */
write(STDOUT_FILENO, shell, count);
free(shell);

write(STDOUT_FILENO, ": ", 2);

sprintf(num, "%d", c_n); /* Convert cmd line num to string to write */
count = strlen(num);
write(STDOUT_FILENO, num, count);

write(STDOUT_FILENO, ": ", 2);

count = strlen(str);
write(STDOUT_FILENO, str, count);

write(STDOUT_FILENO, ": ", 2);

write(STDOUT_FILENO, "not found\n", 10);
}
