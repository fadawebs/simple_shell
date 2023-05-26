#include "shell.h"

/**
 * renumber_history - renumbers the history linked list after changes
 * @info: Structure containing potential arguments. Used to maintain
 *
 * Return: the new histcount
 */

int renumber_history(info_t *info)
{
list_t *node = info->history;
int i = 0;
while (node)
{
node->num = i++;
node = node->next;
}
return (info->histcount = i);
while (node)
{
node->num = i++;
node = node->next;
}
return (info->histcount = i);
}
/**
 * read_history - Reads the command history from a file.
 * @info: Structure containing potential arguments.
 * @param file The name of the file to read from.
 * Return: implementation goes here
 */

int read_history(info_t *info)
{
char *filename = get_history_file(info);
if (!filename)
return (0);

int fd = open(filename, O_RDONLY);
free(filename);
if (fd == -1)
return (0);

/*
 * read_file - Read a file descriptor into a buffer.
 *
 * @param fd The file descriptor to read from.
 * @param buf The buffer to read into.
 * @param len The number of bytes to read.
 * @return The number of bytes successfully read, or -1 on error.
 */

char *buf = read_file(fd);
close(fd);
if (!buf)
return (0);

nt linecount = parse_history(buf, info);
free(buf);
truncate_history(info);
return (linecount);
}

char *read_file(int fd)
{
struct stat st;
fstat(fd, &st);
size_t fsize = st.st_size;
if (fsize < 2)
return (NULL);

char *buf = malloc(fsize + 1);
if (!buf)
return (NULL);
ssize_t rdlen = read(fd, buf, fsize);
buf[fsize] = '\0';
if (rdlen <= 0)
{
free(buf);
return (NULL);
}
return (buf);
}

int parse_history(char *buf, info_t *info)
{
int linecount = 0;
int last = 0;
for (int i = 0; buf[i] != '\0'; i++)
{
if (buf[i] == '\n')
{
buf[i] = '\0';
build_history_list(info, buf + last, linecount++);
last = i + 1;
}
}
if (last != strlen(buf))
{
build_history_list(info, buf + last, linecount++);
}
info->histcount = linecount;
return (linecount);
}

void truncate_history(info_t *info)
{
while (info->histcount >= HIST_MAX)
{
delete_node_at_index(&(info->history), 0);
info->histcount--;
}
renumber_history(info);
}

