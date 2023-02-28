#include "list.h"

/**
 * new_node - Create a new node
 * @list: The list to modify
 * @str:  The string to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *new_node(List **list, char *str)
{
	(*list) = malloc(sizeof(List));
	if (!(*list))
		return (NULL);
	(*list)->str = strdup(str);
	if (!((*list)->str))
		return (NULL);
	(*list)->next = NULL;
	(*list)->prev = NULL;
	return ((*list));
}

/**
 * insert_node - Insert the new node into a double linked circular list
 * @list: The list to modify
 * @str:  The string to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *insert_node(List **list, char *str)
{
	List *tmp = *list, *node = NULL;

	if (!list ||  !str)
		return (NULL);

	if (!(*list))
		return (new_node(&(*list), str));
	node = malloc(sizeof(List));
	if (!node)
		return (NULL);
	node->str = strdup(str);
	node->next = (*list);
	if (tmp->prev)
	{
		node->prev = tmp->prev;
		tmp->prev->next = node;
	}
	else /* !(tmp->next) */
	{
		node->prev = tmp;
		tmp->next = node;
	}
	tmp->prev = node;
	return (node);
}

/**
 * add_node_end - Add a new node to the end
 * of a double circular linked list
 * @list: The list to modify
 * @str:  The string to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	return (insert_node(&(*list), str));
}

/**
 * add_node_begin - Add a new node to the beginning
 * of a double circular linked list
 * @list: The list to modify
 * @str:  The string to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	(*list) = insert_node(&(*list), str);
	return ((*list));
}
