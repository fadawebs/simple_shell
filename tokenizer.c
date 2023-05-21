#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * tbtb_strdup - duplicates a string
 *
 * This function duplicates the input string and returns a pointer to the new
 * string. The memory for the new string is allocated dynamically using malloc.
 *
 * @param str The input string to be duplicated
 * @return A pointer to the duplicated string on success, or NULL on failure
 */
char *tbtb_strdup(const char *str);

int main(void)
{
    const char *str = "Hello, world!";
    char *new_str = tbtb_strdup(str);

    printf("Original: %s\n", str);
    printf("Copy:     %s\n", new_str);

    free(new_str);

    return 0;
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
#define WRITE_BUF_SIZE 1024

int _putchar(char c)
{
    static int i = 0;
    static char buf[WRITE_BUF_SIZE];

    if (c == '\0' || i >= WRITE_BUF_SIZE - 1)
    {
        buf[i] = '\0';
        write(STDOUT_FILENO, buf, i);
        i = 0;
    }
    if (c != '\0')
        buf[i++] = c;

    return 1;
}

/**
 * _strcpy - copies a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, const char *src)
{
    int i = 0;

    if (dest == src || src == NULL)
        return dest;

    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

/**
 * _puts - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _puts(const char *str)
{
    int i = 0;

    if (!str)
        return;

    while (str[i])
    {
        _putchar(str[i]);
        i++;
    }
}

/**
 * char *tbtb_strdup(const char *str)
{
    size_t len = strlen(str) + 1;
    char *new_str = malloc(len);

    if (new_str == NULL)
        return NULL;

    memcpy(new_str, str, len);
    return new_str;
}
*/
