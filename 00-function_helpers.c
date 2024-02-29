#include "shell.h"
/**
 * _strlen - a function that returns the length of a string.
 * @s: the string
 * Return: integer the length
*/
int _strlen(char *s)
{
	int i;
	int len = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		len = i + 1;
	}
	return (len);
}

/**
 * _strdup - a function that returns a pointer to a newly
 * allocated space in memory, which contains a copy of the
 * string given as a parameter.
 * @str: the string
 * Return: a pointer to the duplicated string
*/
char *_strdup(char *str)
{
	int s;
	char *p;

	if (str == NULL)
	{
		return (NULL);
	}
	s = _strlen(str) + 1;
	p = (char *)malloc(s * sizeof(char));

	if (p == NULL)
	{
		return (NULL);
	}
	_strcpy(p, str);
	return (p);
}

/**
 * _strcpy - a function that copies the string pointed to by src,
 *  including the terminating null byte (\0),
 *   to the buffer pointed to by dest.
 * @src: pointer that point to the string
 * @dest: pointer to the buffer
 * Return: a pointer to dest
*/
char *_strcpy(char *dest, char *src)
{
	char *i = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (i);
}

/**
 * _strcmp - a function that compares two strings
 * @s1: pointer
 * @s2: pointer
 * Return: integer (Success)
*/
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
				i++;
	}
	return (0);

}

/**
 * _strcat - a function that concatenates two strings
 * @dest: pointer
 * @src: pointer
 * Return: a pointer to dest
*/
char *_strcat(char *dest, char *src)
{
	char *i = dest;

	while (*i != '\0')
	{
		i++;
	}
	while (*src != '\0')
	{
		*i = *src;
		i++;
		src++;
	}
	*i = '\0';
	return (dest);
}
