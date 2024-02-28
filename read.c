#include "shell.h"
/**
 * read_input - a function that reads a line of input from the
 * standard input (stdin)
 * Return: a pointer to the input string, or NULL if fails
*/
char *read_input(void)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t readin;

	display_prompt();
	readin = getline(&input, &len, stdin);
	if (readin == -1)
	{
		free(input);
		return (NULL);
	}
	return (input);
}
