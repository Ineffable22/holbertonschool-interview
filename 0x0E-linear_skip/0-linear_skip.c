#include "search.h"
#include <stdio.h>

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @list: Is a pointer to the head of the skip list to search in
 * A node of the express lane is placed every index which is a multiple of
 * the square root of the size of the list (see example below)
 * @value: Is the value to search for
 *
 * Return: A pointer on the first node where value is located, If value
 * is not present in list or if head is NULL, your function must return NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *exp = NULL, *tmp = NULL, *node = NULL;
	int i = 0;

	if (list == NULL)
		return (NULL);
	for (exp = list->express; exp; exp = exp->express,
		     list = list->next->next->next->next)
	{
		if (exp->n >= value || !exp->express)
		{
			printf("Value checked at index [%d] = [%d]\n", i + 4, exp->n);
			if (!exp->express && exp->n < value)
			{
				list = list->next->next->next->next;
				i += 4;
			}
			printf("Value found between indexes [%d] and [%d]\n", i, i + 4);
			tmp = list;
			for (; tmp && tmp != list->express && i != 3; tmp = tmp->next)
			{
				if (tmp->n == value)
					node = tmp;
				printf("Value checked at index [%d] = [%d]\n", i, tmp->n);
				i += 1;
			}
			break;
		}
		printf("Value checked at index [%d] = [%d]\n", i += 4, exp->n);
	}
	return (node);
}
