#include "shell.h"
/**
 * _eputs - print input String
 * @str: the String to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}
/**
 * _eputchar - writes the char cc to stderr
 * @cc: The char to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char cc)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (cc == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (cc != BUF_FLUSH)
		buf[i++] = cc;
	return (1);
}
/**
 * _putfd - writes the char cc to given fds
 * @cc: The char to print
 * @fds: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char cc, int fds)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (cc == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fds, buf, i);
		i = 0;
	}
	if (cc != BUF_FLUSH)
		buf[i++] = cc;
	return (1);
}
/**
 * _putsfd - prints an input String
 * @str: the String to be printed
 * @fds: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *str, int fds)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fds);
	}
	return (i);
}
