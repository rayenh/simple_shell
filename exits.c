#include "shell.h"
/**
 **_strncpy - copies String
 *@deste: the destination String copied
 *@srce: the source String
 *@m: the amount of characters to be copied
 *Return: the concatenated String
 */
char *_strncpy(char *deste, char *srce, int m)
{
	int i, j;
	char *s = deste;

	i = 0;
	while (srce[i] != '\0' && i < m - 1)
	{
		deste[i] = srce[i];
		i++;
	}
	if (i < m)
	{
		j = i;
		while (j < m)
		{
			deste[j] = '\0';
			j++;
		}
	}
	return (s);
}
/**
 **_strncat - concatenates two strings
 *@deste: the first String
 *@srce: the second String
 *@m: the amount of bytes to be maximally used
 *Return: the concatenated String
 */
char *_strncat(char *deste, char *srce, int m)
{
	int i, j;
	char *s = deste;

	i = 0;
	j = 0;
	while (deste[i] != '\0')
		i++;
	while (srce[j] != '\0' && j < m)
	{
		deste[i] = srce[j];
		i++;
		j++;
	}
	if (j < m)
		deste[i] = '\0';
	return (s);
}
/**
 **_strchr - locates a character in a String
 *@s: the String to be parsed
 *@c: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
