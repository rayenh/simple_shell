#include "shell.h"

/**
 * interactive
 * @inf: struct address
 *
 * Return: 1 if interactive  0 otherwise
 */
int interactive(info_t *inf)
{
	return (isatty(STDIN_FILENO) && inf->readfd <= 2);
}

/**
 * is_delim - checks if char is a delimeter
 * @c: the char to check
 * @delim: the delimeter String
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - checks for alphab char
 * @c: The char to input
 * Return: 1 if c is alphab, 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts a String to an Integer
 * @ss: the String to be converted
 * Return: 0 if no Numbers in String, Converted Number otherwise
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int rslt = 0;

	for (i = 0; ss[i] != '\0' && flag != 2; i++)
	{
		if (ss[i] == '-')
			sign *= -1;

		if (ss[i] >= '0' && ss[i] <= '9')
		{
			flag = 1;
			rslt *= 10;
			rslt += (ss[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -rslt;
	else
		output = rslt;

	return (output);
}
