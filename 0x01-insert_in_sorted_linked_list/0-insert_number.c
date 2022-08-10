#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list.
 * @head: double pointer of singly linked list.
 * @number: value of node to insert
 *
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *node = NULL;

	if ((*head) == NULL || (*head)->n > number)
	{
		node = calloc(1, sizeof(listint_t));
		if (node == NULL)
			return (NULL);
		node->n = number;
		if (*head)
			node->next = (*head);
		else
			node->next = NULL;
		(*head) = node;
		return (*head);
	}
	else
		(*head)->next = (insert_node(&((*head)->next), number));
	return (*head);
}