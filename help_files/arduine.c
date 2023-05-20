#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "shell.h"

int main(void)
{
    char *args[] = {"ls", "-l", NULL};
    char *path = "/bin";
    char *full_path = get_full_path(path, args[0]);
    if (full_path == NULL)
    {
        printf("Could not find command\n");
        exit(1);
    }
    printf("Full path: %s\n", full_path);

    char *cmd = "ls -l";
    char **cmd_args = tokenize(cmd);
    printf("Command: %s\n", cmd);
    printf("Tokenized arguments:\n");
    for (int i = 0; cmd_args[i] != NULL; i++)
    {
        printf("%s\n", cmd_args[i]);
    }
    free_tokens(cmd_args);

    return 0;
}
