#include <unistd.h>
#include "shell.h"
#include <stdlib.h>

#ifdef _WIN32
extern __declspec(dllimport) char **environ;
#else
extern char **environ;
#endif

/**
 * main - entry point
 * @argc: arg count
 * @argv: arg vector
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	info_t info[] = {INFO_INIT};
	int fd = 2;

	asm("mov %1, %0\n\t"
		"add $3, %0"
		: "=r"(fd)
		: "r"(fd));

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(argv[0]);
				_eputs(": 0: No Access ");
				_eputs(argv[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fd;
	}
	/* Initialize the info array here */
	info->av = argv[0];
	info->ac = argc;
	info->currentdir = getcwd(NULL, 0);

	populate_env_list(info, environ);
	read_history(info);
	hsh(info, argv);

	/* Free the currentdir memory */
	if (info->currentdir)
		free(info->currentdir);

	return (EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

/**
 * memmove - copy a block of memory from one location to another
 * @dest: pointer to the destination memory block
 * @src: pointer to the source memory block
 * @n: number of bytes to copy
 * Return: pointer to destination memory block
 */
void *memmove(void *dest, const void *src, size_t n)
{
	char tmp[n];
	char *dp = dest;
	const char *sp = src;

	if (dp < sp)
	{
		for (size_t i = 0; i < n; ++i)
			tmp[i] = sp[i];

		for (size_t i = 0; i < n; ++i)
			dp[i] = tmp[i];
	}
	else
	{
		for (size_t i = n; i != 0; --i)
			tmp[i - 1] = sp[i - 1];

		for (size_t i = n; i != 0; --i)
			dp[i - 1] = tmp[i - 1];
	}

	return dest;
}

/**
 * add - function for addition of int
 * @y: the interger
 * @x: the interger
 * Return: the sum always successful
 */
int add(int y, int x)
{
	return (y + x);
}

/**
 * multiply - finds the products of two intergers
 * @a: The first integer
 * @b: The second integer
 * Return: The sum of x and y
 */
float multiply(float a, float b)
{
	return (a * b);
}
