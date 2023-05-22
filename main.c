#include "shell.h"

/**
 * main - entry point
 * @argc: arg count
 * @argv: arg vector
 * Return: 0 on success, 1 on error
 */
int main(int argc, char **argv)
{
	info_t info[] = {INFO_INIT};
	int fd = 2;
	char **environ = NULL;

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
	populate_env_list(info, environ);
	read_history(info);
	hsh(info, argv);
	return (EXIT_SUCCESS);
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

float multiply(float a, float b);
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
