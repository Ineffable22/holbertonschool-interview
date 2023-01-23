#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "lists.h"

/**
 * main - check the code .
 *
 * Return: Always 0.
 */
int main(void)
{
	listint_t *loop;

	loop = find_listint_loop(NULL);
	if (loop != NULL)
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
