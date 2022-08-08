#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list.
 * @head: double pointer of singly linked list.
 * @number: index of node to insert
 *
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *node = NULL, *tmp = *head, *prev = NULL;

	node = calloc(1, sizeof(listint_t));
	if (node == NULL)
		return (NULL);
	node->n = number;
	node->next = NULL;

	if (number == 0)
	{
		if ((*head) != NULL)
			node->next = (*head);
		(*head) = node;
		return (*head);
	}
	for (; tmp->n < number; tmp = tmp->next)
		prev = tmp;
	prev->next = node;
	node->next = tmp;
	return (*head);
}
