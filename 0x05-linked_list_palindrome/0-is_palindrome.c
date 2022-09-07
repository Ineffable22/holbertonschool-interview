#include "lists.h"

/**
 * node - Search a node by index
 * @head: Pointer to singly linked list
 * @idx: Index to compare
 *
 * Return: The searched value
 */
int node(listint_t *head, int idx)
{
	if (idx != 0)
		return (node(head->next, idx - 1));

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
	if (total <= 0)
		return (1);

	if (head->n == node(head, total))
		return (check(head->next, total - 2));

	return (0);
}

/**
 * length - Calculates length
 * @head: Pointer to singly linked list
 *
 * Return: Length
 **/
int length(listint_t *head)
{
	if (head)
		return (length(head->next) + 1);
	return (0);
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome
 * @head: Pointer to singly linked list
 *
 * Return: 1 is palindrome, 0 othewise
 */
int is_palindrome(listint_t **head)
{
	int len = 0;

	if (!head || !*head)
		return (1);

	len = length(*head);
	return (check(*head, len - 1));
}
