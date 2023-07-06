#include "lists.h"

/**
 * reverse_listint - reverses a linked list
 * @head: head of a list.
 *
 * Return: poitner to the first node.
 */
listint_t *reverse_listint(listint_int **head)
{
	listint_t *p;
	listint_t *n;

	p = NULL;
	n = NULL;

	while (*head != NULL)
	{
		n = (*head)->next;
		(*head)->next = p;
		p = *head;
		*head = n;
	}

	*head = p;
	return (*head);
}
