#include "shell.h"

/**
 * _strcat - copy string to another string.
 * @dst: character
 * @src: character
 *
 * Return: dst
 */

char *_strcat(char *dst, char *src)
{
	int d = 0;
	int s = 0;

	while (dst[d] != '\0')
	{
		d++;
	}
	while (src[s] != '\0')
	{
		dst[d] = src[s];
		d++;
		s++;
	}
	dst[d] = '\0';
	return (dst);
}

/**
 * _strcmp - Compare the values of a string
 * @S: char
 * @Z: char
 *
 * Return: 0
 */

int _strcmp(char *S, char *Z)
{
	int a;

	for (a = 0; S[a] != '\0' && Z[a] != '\0'; a++)
	{
		if (S[a] != Z[a])
			return ((int)S[a] - Z[a]);
	}
	return (0);
}

/**
 * _strlen - Copies the string pointed to into destination
 * @s: pointer
 *
 * Return: char pointer to dst
 */

int _strlen(char *s)
{
	int c = 0;

	while (*(s + c) != '\0')
	{
		c++;
	}

	return (c);
}

/**
 * _strncmp - Compare fonction with two strings.
 * @S1: string 
 * @S2: string
 * @n: number of chars
 *
 * Return: difference
 */

size_t _strncmp(char *S1, char *S2, size_t n)
{
	size_t i, j;

	for (j = 0; S1[j] != '\0' && j < n; j++)
	{
		i = S1[j] - S2[j];

		if (i != 0)
		{
			return (i);
		}
	}
	return (0);
}

/**
 * _strcpy - Copies the string pointed to source into destination.
 * @dst: destination of the copy
 * @src: source of the copy
 *
 * Return: char pointer to dst
 */

char *_strcpy(char *dst, char *src)
{
	int i = 0;

	while (*(src + i) != '\0')
	{
		*(dst + i) = *(src + i);
		++i;
	}
	*(dst + i) = *(src + i);

	return (dst);
}
