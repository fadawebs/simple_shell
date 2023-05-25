#include "shell.h"


/**
 * get_input - gets a line of input from STDIN
 * @info: parameter struct
 *
 * Return: bytes read
 */
ssize_t get_input(info_t *info)
{
static char buf[READ_BUF_SIZE];
static size_t i, j, len;
ssize_t r = 0;
char **buf_p = &(info->arg), *p;

_putchar(BUF_FLUSH);
r = read_buf(info, buf, &len);
if (r == -1)
return (-1);
if (len)
{
j = i;
p = buf + i;

check_chain(info, buf, &j, i, len);
while (j < len)
{
if (is_chain(info, buf, &j))
break;
j++;
}

i = j + 1;
if (i >= len)
{
i = len = 0;
info->cmd_buf_type = CMD_NORM;
}

*buf_p = p;
return (_strlen(p));
}

*buf_p = buf;
return (r);
}

/**
 * read_buf - reads a buffer
 * @info: parameter struct
 * @buf: buffer
 * @i: size
 *
 * Return: r
 */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
ssize_t r = 0;

if (*i)
return (0);
r = read(info->readfd, buf, READ_BUF_SIZE);
if (r >= 0)
*i = r;
return (r);
}

/**
 * sigintHandler - blocks ctrl-C
 * @sig_num: the signal number
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused)) int sig_num)
{
_puts("\n");
_puts("Beekaz$ ");
_putchar(BUF_FLUSH);
}
