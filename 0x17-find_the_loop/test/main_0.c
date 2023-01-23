#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "lists.h"

/**
 * _add_node - Add a node at the beginning of a list
 *
 * @head: A pointer to the first element of a list
 * @n: The number to store in the new node
 *
 * Return: The address of the new node
 */
listint_t *_add_node(listint_t **head, int n)
{
	listint_t *tmp;

	tmp = malloc(sizeof(*tmp));
	if (!tmp)
		return (NULL);
	tmp->n = n;
	tmp->next = *head;
	*head = tmp;
	return (tmp);
}

/**
 * main - check the code .
 *
 * Return: Always 0.
 */
int main(void)
{
	listint_t *head;
	listint_t *node;
	listint_t *loop;

	head = NULL;
	node = _add_node(&head, 9);
	node->next = _add_node(&head, 6);
	loop = find_listint_loop(head);
	if (loop != node->next)
	{
		printf("The address returned is not the good one.\n");
		return (1);
	}
	if (loop)
		printf("%d\n", loop->n);
	else
		printf("(nil)\n");
	return (0);
}
