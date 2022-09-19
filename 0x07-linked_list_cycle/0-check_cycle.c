#include "lists.h"

/**
 * check_cycle - Checks if a singly linked list has a cycle in it.
 * @list: Pointer to Singly Linked List
 *
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *slow = NULL, *fast = NULL;

	if (!list)
		return (0);

	slow = list->next;
	fast = list->next->next;
	while (fast)
	{
		if (slow->n == fast->n)
			return (1);
		slow = slow->next;
		fast = fast->next->next;
	}
	return (0);
}
