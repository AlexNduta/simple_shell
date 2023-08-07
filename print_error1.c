#include "shell.h"

/**
* cant_cd_to - write error ("sh: 2: cd: can't cd to xyz")
* @directory: user's typed argument after the cmd cd
* @error_code: nth user's typed command
* @env: bring in environmental variables linked list to write shell name
*/
void cant_cd_to(char *directory, int error_code, list_t *env)
{
int count = 0;
char *shell, *num;

shell = get_env("_", env);
count = strlen(shell);
write(STDOUT_FILENO, shell, count);
free(shell);
write(STDOUT_FILENO, ": ", 2);
num = int_to_string(error_code);
count = strlen(num);
write(STDOUT_FILENO, num, count);
free(num);
write(STDOUT_FILENO, ": ", 2);
write(STDOUT_FILENO, "cd: can't cd to ", 16);
count = strlen(directory);
write(STDOUT_FILENO, directory, count);
write(STDOUT_FILENO, "\n", 1);
}

/**
* illegal_number - write error ("sh: 3: exit: Illegal number abc (or -1)")
* @str: user's typed argument after the cmd exit
* @c_n: nth user's typed command
* @env: bring in environmental variables linked list to write shell name
*/
void illegal_number(char *str, int c_n, list_t *env)
{
int count;
char *num;
char *shell = get_env("_", env);

count = strlen(shell);
write(STDOUT_FILENO, shell, count);
free(shell);

write(STDOUT_FILENO, ": ", 2);

num = int_to_string(c_n);
count = strlen(num);
write(STDOUT_FILENO, num, count);
free(num);

write(STDOUT_FILENO, ": exit: Illegal number: ", 22);

count = strlen(str);
write(STDOUT_FILENO, str, count);
write(STDOUT_FILENO, "\n", 1);
}

