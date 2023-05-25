#include "shell.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


/**
 * get_input - reads input from stdin into a buffer
 * @info: pointer to info struct
 * Return: number of bytes read or -1 on error
 */
ssize_t get_input(info_t *info)
{
char buffer[BUFFER_SIZE];
ssize_t bytes_read;

info->fname = malloc(BUFFER_SIZE);
if (info->fname == NULL)
{
fprintf(stderr, "Memory allocation error\n");
exit(1);
}

bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
if (bytes_read == -1)
{
perror("read");
return (-1);
}

if (bytes_read == 0)
{
return (-1);
}

memcpy(info->fname, buffer, bytes_read);
info->fname[bytes_read] = '\0';

return (bytes_read);
}

/**
 * fork_cmd - executes a command using fork and exec
 * @info: pointer to info struct
 */
void fork_cmd(info_t *info)
{
(void)info;
}

/**
 * print_prompt - prints the shell prompt
 */
void print_prompt(void)
{
printf("Beekaz$: ");
}

/**
 * hsh - main shell loop
 * @info: pointer to info struct
 * @av: array of strings
 * Return: exit status
 */
int hsh(info_t *info, char **av)
{
ssize_t r;
int builtin_ret = 0;

while ((r = get_input(info)) != -1 && builtin_ret != -2)
{
clear_info(info);

if (interactive(info))
print_prompt();

if (r != -1)
{
set_info(info, av);
builtin_ret = find_builtin(info);
if (builtin_ret == -1)
fork_cmd(info);
}
else if (interactive(info))
{
putchar('\n');
}

free_info(info, 0);
}

write_history(info);
free_info(info, 1);

if (!interactive(info) && info->status)
exit(info->status);

if (builtin_ret == -2)
{
if (info->err_num == -1)
exit(info->status);
exit(info->err_num);
}

return (builtin_ret);
}



/**
 * find_builtin - finds and executes a builtin command
 * @info: pointer to info struct
 * Return: exit status of the builtin command
 */

void fork_cmd(info_t *info)
{
int i, built_in_ret = -1;
builtin_table builtintbl[] = {
{"env", _shellenv},
{"exit", _shellexit},
{"help", _shellhelp},
{"setenv", _shellsetenv},
{"unsetenv", _shellunsetenv},
{"history", _shellhistory},
{"alias", _shellalias},
{"cd", _shellcd},
{NULL, NULL}};

info->argv = malloc(10 * sizeof(char *));
if (info->argv == NULL)
{
fprintf(stderr, "Error in memory allocation\n");
exit(1);
}

for (i = 0; builtintbl[i].type; i++)
{
if (_strcmp(info->argv[0], builtintbl[i].type) == 0)
{
info->line_count++;
return
(built_in_ret = builtintbl[i].func(info));
break;
}
}
return (-1);
}

