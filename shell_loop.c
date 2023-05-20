#include "shell.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * get_input - will allow you to have more control over its behavior
 *  @info: the parameter & return info struct
 * Return: void
 */

ssize_t get_input(info_t *info)
{
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;
    info_t temp = {0};
    *info = temp;
    bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
    if (bytes_read == -1)
    {
        return (-1);
    }
    memcpy(temp->input, buffer, bytes_read);
    return (bytes_read);
}

/**
 * fork_cmd - finds a command in PATH
 * @info: the parameter & return info struct
 * Return: void
 */

void fork_cmd(info_t *info)
{
    char *path = NULL;
    int i, k;

    info->path = info->argv[0];
    if (info->linecount_flag == 1)
    {
        info->line_count++;
        info->linecount_flag = 0;
    }
    for (i = 0, k = 0; info->argv[i]; i++)
        if (!is_delim(*(info->argv[i]), " \t\n"))
            k++;
    if (!k)
        return;
    path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
    if (path)
    {
        info->path = path;
        fork_cmd(info);
    }
    else
    {
        if ((interactive(info) || _getenv(info, "PATH=") ||
             info->argv[0][0] == '/') &&
            is_cmd(info, info->argv[0]))
            fork_cmd(info);
        else if (*(info->argv)[0] != '\n')
        {
            info->status = 127;
        }
    }
}

void print_prompt(void);
/**
 * print_prompt -  function simply prints the string
 * Return: no value or  NULL
 */

void print_prompt(void)
{
    printf("Enter a command: ");
}
/**
 * hsh - main shell loop
 * @info: the array of pointers to char pointers
 * @argv: array of strings
 * Return: 0 on success, 1 on error, or error code
 */

int hsh(info_t *info, char **argv)
{
    ssize_t r = 0;
    int builtin_ret = 0;

    while (r != -1 && builtin_ret != -2)
    {
        clear_info(info);
        if (interactive(info))
            print_prompt();
        r = get_input(info);
        if (r != -1)
        {
            (void)set_info(info, argv);
            builtin_ret = find_builtin(info);
            if (builtin_ret == -1)
                fork_cmd(info);
        }
        else if (interactive(info))
            _putchar('\n');
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
 * find_builtin - finds a builtin command
 * @info: the parameter & return info struct
 *
 * Return: -1 if builtin not found,
 *			0 if builtin executed successfully,
 *			1 if builtin found but not successful,
 *			-2 if builtin signals exit()
 */
int find_builtin(info_t *info)
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

    for (i = 0; builtintbl[i].type; i++)
        if (_strcmp(info->argv[0], builtintbl[i].type) == 0)
        {
            info->line_count++;
            built_in_ret = builtintbl[i].func(info);
            break;
        }
    return (built_in_ret);
}
