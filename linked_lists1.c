#include "shell.h"
/**
* delete_nodeint_at_index - Removes a node at index in the linked list.
* @head: Pointer to the pointer of the head of the linked list.
* @index: Index of the node to be removed.
* Return: 1 if successful, -1 if failed.
*/
int delete_nodeint_at_index(list_t **head, int index)
{
list_t *temp;
list_t *previous;
int count = 0;

if (*head == NULL)
return (-1);

if (index == 0)
{
temp = (*head)->next;
free((*head)->var);
free(*head);
*head = temp;
return (1);
}

count = 1;
temp = *head;
while (count < index)
{
if (temp == NULL)
return (-1);
temp = temp->next;
count++;
}

previous = temp->next;
temp->next = previous->next;
free(previous->var);
free(previous);

return (1);
}
/**
 *free_linked_list- frees the memomry of our list
 *@list: our linked list
 */
void free_linked_list(list_t *list)
{
list_t *current;

while (list != NULL)
{
current = list;
list = list->next;
free(current->var);
free(current);
}
}

