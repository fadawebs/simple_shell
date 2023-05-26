#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (i >= WRITE_BUF_SIZE || c == BUF_FLUSH)
	{
		write(STDOUT_FILENO, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
	{
		buf[i++] = c;
	}

	return (1);
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
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
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
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);

	/*   Calculate string length   */
	while (str[length] != '\0')
		length++;

	ret = malloc(sizeof(char) * (length + 1));
	if (ret == NULL)
		return (NULL);

	for (int i = length - 1; i >= 0; i--)
		ret[i] = str[i];

	return (ret);
}
