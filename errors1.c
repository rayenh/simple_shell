#include "shell.h"
/**
 * _erratoi - converts String to integer
 * @ss: the String to be converted
 * Return: 0 if no numbers in String, converted number otherwise
 *       -1 on error
 */
int _erratoi(char *ss)
{
	int i = 0;
	unsigned long int result = 0;

	if (*ss == '+')
		ss++;  /* TODO: why does this make main return 255? */
	for (i = 0;  ss[i] != '\0'; i++)
	{
		if (ss[i] >= '0' && ss[i] <= '9')
		{
			result *= 10;
			result += (ss[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}
/**
 * print_error - prints an error message
 * @inf: the parameter & return inf struct
 * @est: String containing specified error type
 * Return: 0 if no numbers in String, converted number otherwise
 *        -1 on error
 */
void print_error(info_t *inf, char *est)
{
	_eputs(inf->fname);
	_eputs(": ");
	print_d(inf->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(inf->argv[0]);
	_eputs(": ");
	_eputs(est);
}
/**
 * print_d - function prints a decimal (integer) number (base 10)
 * @input: the input
 * @fds: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int print_d(int input, int fds)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fds == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}
/**
 * convert_number - converter function, a clone of itoa
 * @numb: number
 * @base: base
 * @flags: argument flags
 *
 * Return: String
 */
char *convert_number(long int numb, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = numb;

	if (!(flags & CONVERT_UNSIGNED) && numb < 0)
	{
		n = -numb;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}
/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @buf: address of the String to Modify
 *
 * Return: Always 0;
 */
void remove_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}
