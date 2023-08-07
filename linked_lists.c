#include "shell.h"
/**
*print_list- prints our list
*@head: head of linked list
*Return: the size of the linked_list
*/
size_t print_list(list_t *head)
{
list_t *current;
int count = 0;

if (head == NULL)
{
return (0);
}

for (current = head; current != NULL; current = current->next)
{
if (current->var == NULL)
{
write(STDOUT_FILENO, "(nil)\n", 6);
}
else
{
write(STDOUT_FILENO, current->var, strlen(current->var));
write(STDOUT_FILENO, "\n", 1);
}
count++;
}

return (count);
}

/**
 *add_end_node- adds a node to our list
 *@head: head of the list
 *@str: what to add to the new list
 *Return: pointer to our new list
 */
list_t *add_end_node(list_t **head, char *str)
{
list_t *new_node;
list_t *current;

if (head == NULL || str == NULL)
return (NULL);

new_node = malloc(sizeof(list_t));
if (new_node == NULL)
return (NULL);

new_node->var = _strdup(str);
new_node->next = NULL;

current = *head;
if (current != NULL)
{
while (current->next != NULL)
current = current->next;

current->next = new_node;
}
else
{
*head = new_node;
}

return (*head);
}
