#include "lists.h"

/**
 * free_list - this frees a list
 * @head: the head of the linked list.
 * Return: a no return.
 */

void free_list(list_t *head)
{
	list_t *current;


	while ((current = head) != NULL)
	{

		head = head->next;
		free(current->str);
		free(current);

	}
}

