
#include "shell.h"

/**
* env_linked_list - returns a pointer to a structure
* of type list which represents the headof a
* linked list.
* @env: a pointer to a pointer of character
* Return: head pointer of the constructed linked list
*/
list_t *env_linked_list(char **env)
{
list_t *head = NULL;
int i = 0;

do {
if (env[i] == NULL)
{
break;
}
add_end_node(&head, env[i]);
i++;
} while (env[i] != NULL);

return (head);
}
/**
* _env - used to get an environment variable value
* @str: pointer to a pointer of characters
* @env: a pointer to a linked list
* Return: 0 integer value
*/
int _env(char **str, list_t *env)
{
do {
free_double_ptr(str);
print_list(env);
} while (0);

return (0);
}

