#include "shell.h"

/**
 * print_list - Prints the contents of a linked list.
 * @h: Pointer to the head node.
 *
 * Return: Number of nodes in the list.
 */
size_t print_list(const list_t *head)
{
	size_t i = 0;

	while (head)
	{
		_puts(convert_number(head->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(head->str ? head->str : "(nil)");
		_puts("\n");
		head = head->next;
		i++;
	}
	return (i);
}


/**
 * list_len_t - Returns the number of nodes in a linked list.
 * @head: Pointer to the head node.
 * Return: Number of nodes.
 */

size_t list_len(const list_t *head)
{
	size_t i = 0;

	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}


/**
 * get_node_index - Returns the index of a node in a linked list.
 * @head: Pointer to the head node.
 * @node: Pointer to the node to search for
 * Return: Index of the node or -1 if the node is not in the list.
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}

/**
 * list_to_strings - Returns an array of strings containing the contents of a
 * linked list.
 * @head: Pointer to the head node.
 *
 * Return: Pointer to the array of strings.
 */

char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t i = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * node_starts_with - Returns the first node in a linked list whose string
 * starts with a given prefix.
 * @head: Pointer to the head node.
 * @prefix: Prefix to match.
 * @c: Character that comes after the prefix.
 *
 * Return: Pointer to the matching node or NULL.
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

