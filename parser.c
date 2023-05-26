#include "shell.h"



/**
 * find_path - finds this cmd in the PATH string
 * @info: the info struct
 * @pathstr: the PATH string
 * @cmd: the cmd to find
 *
 * Return: full path of cmd if found or NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
int i = 0, curr_pos = 0;
char *path;

if (!pathstr)
return (NULL);
if (_strlen(cmd) > 2 && starts_with(cmd, "./"))
{
if (is_cmd(info, cmd))
return (cmd);
}
while (1)
{
if (!pathstr[i] || pathstr[i] == ':')
{
path = dup_chars(pathstr, curr_pos, i);
if (!*path)
_strcat(path, cmd);
{
_strcat(path, "/");
_strcat(path, cmd);
}
if (is_cmd(info, path))
return (path);
free(path);
if (!pathstr[i])
break;
curr_pos = i + 1;
}
i++;
}
return (NULL);
}

/**
 * is_cmd - determines if a file is an executable command
 * @info: the info struct
 * @path: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int is_cmd(info_t *info, char *path)
{
struct stat st;
(void)info;

if (!path || stat(path, &st) || !(st.st_mode & S_IFREG))
return (0);

return (1);
}

/**
 * dup_chars - duplicates characters
 * @pathstr: the PATH string
 * @start: starting index
 * @stop: stopping index
 *
 * Return: pointer to new buffer
 */
char *dup_chars(const char *pathstr, int start, int stop)
{
size_t buf_size = (size_t)(stop - start + 1);
char *buf = malloc(buf_size);

if (buf != NULL)
{
const char *src = pathstr + start;
char *dst = buf;

while (start < stop && *src != '\0')
{
if (*src != ':')
{
*dst++ = *src;
}

src++;
}

*dst = '\0';
}

return (buf);
}
