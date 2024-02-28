#include "shell.h"
/**
 * tokenize_input - a function that tokenizes a string into an
 * array of strings based on a delimiter.
 * @input: the input string to be tokenized
 * Return: an array of strings representing the tokens,
 * or NULL if the input is NULL or memory fails
*/
char **tokenize_input(char *input)
{
	char **commands = NULL;
	char *tokn = NULL, *temv = NULL;
	int count = 0, i = 0;

	if (!input)
		return (NULL);
	temv = _strdup(input);
	if (!temv)
		return (NULL);
	tokn = strtok(temv, DELIM);
	if (tokn == NULL)
	{
		free(input);
		free(temv);
		return (NULL);
	}
	while (tokn)
	{
		count++;
		tokn = strtok(NULL, DELIM);
	}
	free(temv);
	commands = malloc(sizeof(char *) * (count + 1));
	if (!commands)
	{
		free(input);
		return (NULL);
	}
	tokn = strtok(input, DELIM);
	while (tokn)
	{
		commands[i] = _strdup(tokn);
		tokn = strtok(NULL, DELIM);
		i++;
	}
	free(input);
	commands[i] = NULL;

	return (commands);
}
