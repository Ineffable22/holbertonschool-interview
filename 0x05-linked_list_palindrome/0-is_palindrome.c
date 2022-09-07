#include "lists.h"

/**
 * node - Search a node by index
 * @head: Pointer to singly linked list
 * @i: Index to compare
 *
 * Return: The searched value
 */
int node(listint_t *head, int i)
{
	if (i != 0)
		return (node(head->next, i - 1));
	return (head->n);
}

/**
 * check - Compare if a palindrome
 * @head: Pointer to singly linked list
 * @total: Total Nodes
 *
 * Return: 1 is palindrome, 0 othewise
 */
int check(listint_t *head, int total)
{
	listint_t *tmp = head;
	int i = total, j = 0;

	if (i == 0)
		return (1);
	while (j <= total / 2)
	{
		if (node(tmp, j) != node(tmp, i))
			return (0);
		j++;
		i--;
	}
	return (1);
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome
 * @head: Pointer to singly linked list
 *
 * Return: 1 is palindrome, 0 othewise
 */
int is_palindrome(listint_t **head)
{
	listint_t *tmp = NULL;
	int i = 0;

	if (!head || !*head)
		return (1);

	tmp = *head;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (check(*head, i - 1));
}
