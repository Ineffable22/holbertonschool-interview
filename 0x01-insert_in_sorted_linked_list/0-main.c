#include "lists.h"
/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
	listint_t *head = NULL, *node = NULL;

	add_nodeint_end(&head, 0);
	add_nodeint_end(&head, 1);
	add_nodeint_end(&head, 2);
	add_nodeint_end(&head, 3);
	add_nodeint_end(&head, 4);
	add_nodeint_end(&head, 98);
	add_nodeint_end(&head, 402);
	add_nodeint_end(&head, 1024);
	print_listint(head);

	printf("-----------------\n");
	node = insert_node(&head, -1);
	print_listint(head);
	printf("Node Address | value ->%d\n", node->n);

	printf("-----------------\n");
	node = insert_node(&head, 4096);
	print_listint(head);
	printf("Node Address | value ->%d\n", node->n);

	printf("-----------------\n");
	node = insert_node(&head, 5);
	print_listint(head);
	printf("Node Address | value ->%d\n", node->n);

	best_free_listint(&head);

	printf("-----------------\n");
	node = insert_node(&head, 22);
	print_listint(head);
	printf("Node Address | value ->%d\n", node->n);

	best_free_listint(&head);
	printf("-----------------\n");
	print_listint(head);

	return (0);
}
