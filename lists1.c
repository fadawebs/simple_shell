#include "shell.h"

/**
 * list_len_t - Returns the number of nodes in a linked list.
 * @head: Pointer to the head node.
 * Return: Number of nodes.
 */

size_t list_len_t(const list_t *head)
{
size_t count = 0;

while (head)
{
head = head->next;
count++;
}
return (count);
}

/*size_t list_len(const list_t *list)*/

/**
 * list_to_strings - Returns an array of strings containing the contents of a
 * linked list.
 * @head: Pointer to the head node.
 *
 * Return: Pointer to the array of strings.
 */

char **list_to_strings(list_t *head)
{
struct list;

size_t len = list_len_t(head), i;
char **strs;
char *str;

if (!head || !len)
return (NULL);
strs = malloc(sizeof(char *) * (len + 1));
if (!strs)
return (NULL);
for (i = 0; head; head = head->next, i++)
{
str = malloc(_strlen(head->str) + 1);
if (!str)
{
for (; i > 0; i--)
free(strs[i - 1]);
free(strs);
return (NULL);
}

str = _strcpy(str, head->str);
strs[i] = str;
}
strs[i] = NULL;
return (strs);
}

/**
 * print_list - Prints the contents of a linked list.
 * @h: Pointer to the head node.
 *
 * Return: Number of nodes in the list.
 */
size_t print_list(const list_t *h)
{

size_t count = 0;

while (h)
{
_puts(convert_number(h->num, 10, 0));
_putchar(':');
_putchar(' ');
_puts(h->str ? h->str : "(nil)");
_puts("\n");
h = h->next;
count++;
}
return (count);
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
list_t *node_starts_with(list_t *head, char *prefix, char c)
{
char *p = NULL;

while (head)
{
p = starts_with(head->str, prefix);
if (p && ((c == -1) || (*p == c)))
return (head);
head = head->next;
}
return (NULL);
}

/**
 * get_node_index - Returns the index of a node in a linked list.
 * @head: Pointer to the head node.
 * @node: Pointer to the node to search for
 * Return: Index of the node or -1 if the node is not in the list.
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
size_t index = 0;

while (head)
{
if (head == node)
return (index);
head = head->next;
index++;
}
return (-1);
}
