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
	skiplist_t *tmp = NULL;

	if (list)
	{
		while (value > list->n && list->next)
		{
			tmp = list;
			list = list->express;
			if (!list)
			{
				list = tmp;
				while (list->next)
					list = list->next;
			}
			if (list != tmp->express)
				break;
			printf("Value checked at index [%ld] = [%d]\n", list->index,
			       list->n);
		}
		printf("Value found between indexes [%ld] and [%ld]\n",
		       tmp->index, list->index);
		while (tmp && tmp->index <= list->index)
		{
			printf("Value checked at index [%ld] = [%d]\n", tmp->index, tmp->n);
			if (value == tmp->n)
				return (tmp);
			tmp = tmp->next;
		}
	}
	return (NULL);
}
