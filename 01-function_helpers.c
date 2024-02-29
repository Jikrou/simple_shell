#include "shell.h"
/**
 * cleanup_mem - this function fress the memory allocated for an arra
 * of strings.
 * @str: an array of strings to be freed.
 * Return: None
*/
void cleanup_mem(char **str)
{
	int i;

	if (!str)
		return;

	for (i = 0; str[i]; i++)
	{
		free(str[i]);
		str[i] = NULL;
	}
	free(str);
}

/**
 * _getenv - a function that retrieve the value of a specified environment
 * variable.
 * @var: name of the environment variable
 * Return: a pointer to the environment var if found, NULL if not found
*/
char *_getenv(char *var)
{
	char *tmev, *del, *woth, *env = NULL;
	int j = 0;

	for (j = 0; environ[j]; j++)
	{
		tmev = _strdup(environ[j]);
		del = strtok(tmev, "=");
		if (_strcmp(del, var) == 0)
		{
			woth = strtok(NULL, "\n");
			env = _strdup(woth);
			free(tmev);
			return (env);
		}
		free(tmev);
	}
	return (NULL);
}

/**
 * printmsg_error - prints an error msg to stderr indicating
 * that a command was not found
 * @name: name of the program
 * @comand: command that was not found.
 * @indx: the index of the command in the command list.
*/
void printmsg_error(char *name, char *comand, int indx)
{
	char *ix, msg[] = ": not found\n";

	ix = _itao(indx);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, ix, _strlen(ix));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, comand, _strlen(comand));
	write(STDERR_FILENO, msg, _strlen(msg));
	free(ix);
}

/**
 * rev_string - a function that print a string
 * @s: the string to be reversed.
 * @len: the length of the string.
 * Return: no value
*/
void rev_string(char *s, int len)
{
int i = 0;
int c = len - 1;
char rev;

while (i < c)
{
rev = s[i];
s[i] = s[c];
s[c] = rev;
c--;
}
}

/**
 * _itao - converts an integer to its string representation
 * @m: The integer to be converted
 * Return: a dynamically allocated string representing the int
*/
char *_itao(int m)
{
	char buffer[15];
	int i = 0;

	if (m == 0)
		buffer[i++] = '0';
	else
	{
		while (m > 0)
		{
			buffer[i++] = (m % 10) + '0';
			m /= 10;
		}
	}
	buffer[i] = '\0';
	rev_string(buffer, i);

	return (_strdup(buffer));
}
