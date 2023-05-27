#include "shell.h"


/**
 * build_history_list - adds entry to a history linked list
 * @info: Structure containing potential arguments. Used to maintain
 * @buf: buffer
 * @linecount: the history linecount, histcount
 * Return: list goes here
 */
int build_history_list(info_t *info, char *buf, int linecount)
{
list_t *node = info->history;

add_node_end(&node, buf, linecount);

if (!info->history)
info->history = node;

return (0);
}


/**
 * write_history - creates a file, or appends to an existing file
 * @info: the parameter struct
 *
 * Return: 1 on success, else -1
 */

int write_history(info_t *info)
{
ssize_t fd;
char *filename = get_history_file(info);

list_t *node = NULL;

if (!filename)
return (-1);

fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);

free(filename);
if (fd == -1)
return (-1);

for (node = info->history; node; node = node->next)
{
_putsfd(node->str, fd);
_putfd('\n', fd);
}
_putfd(BUF_FLUSH, fd);
close(fd);
return (1);
}


/**
 * get_history_file - gets the history file
 * @info: parameter struct
 * Return: allocated string containing history file
 */
char *get_history_file(info_t *info)
{
	char *buf, *dir;
	size_t dir_len, file_len;

	dir = _getenv(info, "HOME=");
	if (!dir)
		return (NULL);

	dir_len = _strlen(dir);
	file_len = _strlen(HIST_FILE);
	buf = malloc(sizeof(char) * (dir_len + file_len + 2));
	if (!buf)
		return (NULL);

	buf[0] = '\0';
	_strcpy(buf, dir);
	_strcat(buf, "/");
	_strcat(buf, HIST_FILE);
	return (buf);
}

