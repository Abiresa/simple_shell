#include "shell.h"

/**
 * _strtok - Breaks the string s into tokens and null-terminates them.
 * @str: string to tokenize.
 * @delim: string that delimit str.
 *
 * Return: the next token, or a null pointer.
 */

char *_strtok(char *str, const char *delim)
{
	static char *p;

	if (str)
		p = str;
	else if (!p)
		return (0);
	str = p + _strspn(p, delim);
	p = str + _strcspn(str, delim);
	if (p == str)
		return (p = 0);
	p = *p ? *p = 0, p + 1 : 0;
	return (str);
}

/**
 * _strcspn - Computes the length of the max initial segment of the string pointed to consists entirely of chars.
 * @S1: string to check.
 * @S2: string to compare.
 *
 * Return: the length of the segment.
 */

size_t _strcspn(const char *S1, const char *S2)
{
	size_t r = 0;

	while (*S1)
	{
		if (_strchr(S2, *S1))
			return (r);
		S1++, r++;
	}

	return (r);
}

/**
 * _strspn - Computes the length of the max initial segment of the string pointed to S1 from the string S2.
 * @S1: string to compute the lenght.
 * @S2: string delimit.
 *
 * Return: the length of the segment.
 */

size_t _strspn(const char *S1, const char *S2)
{
	size_t r = 0;

	while (*S1 && _strchr(S2, *S1++))
		r++;
	return (r);
}

/**
 * _strchr - Locates the first occurence of c in the string pointed to s.
 * The NULL character is a part of the string.
 * @s: string.
 * @c: character.
 *
 * Return: a pointer to the located chararcter, or a null pointer if the character doesn't occure in the string.
 */

char *_strchr(const char *s, int c)
{
	while (*s != (char)c)
		if (!*s++)
			return (0);
	return ((char *)s);
}
