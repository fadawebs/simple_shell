#include "shell.h"

/**
 * unset_alias - convert alias to string
 * @info: parameter structure
 * @str: string alias
 *
 * Return: Always 0 upon success, while 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
							   get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - converts alias to string
 * @info: params structure
 * @str: string alias
 *
 * Return: Always 0 on success, while 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *equal_sign;

	equal_sign = _strchr(str, '=');

	if (equal_sign == NULL)
	{
		return (1);
	}
	if (*(equal_sign + 1) == '\0')
	{
		return (unset_alias(info, str));
	}
	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) != NULL);
}

/**
 * print_alias - prints alias string
 * @node: the alias node module
 *
 * Return: Always 0 on success, while1 on error
 */
int print_alias(list_t *node)
{
if (node)
{
char *p = _strchr(node->str, '=');

if (p)
{
size_t len = p - node->str;
for (size_t i = 0; i < len; i++)
{
_putchar(node->str[i]);
}
_putchar('\'');
_puts(p + 1);
_puts("'\n");
return (0);
}
}
return (1);
}

/**
 * _shellalias - prototype alias builtin (man alias)
 * @info: Potential arguments present. Used to maintain constant function.
 *  Return: Always 0
 */
int _shellalias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}

	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		node = node_starts_with(info->alias, info->argv[i], '=');
		if (p)
		{
			set_alias(info, info->argv[i]);
		}
		else if (node)
		{
			print_alias(node);
		}
	}

	return (0);
}

/**
 * _shellhistory - Uploads history list, one command per line.
 * @info: Potential arguments present.
 *  Return: Always 0
 */
int _shellhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}
