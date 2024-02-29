#include "shell.h"
/**
 * shell_mode - a function that implements an interactive mode for processing
 * commands.
 * @ac: the number of command-line arguments.
 * @av: An array of strings representing the command-line arguments
 * Return: None
*/
int shell_mode(int ac, char **av)
{
char *input = NULL;
char **cmd = NULL;
int status = 0, idx = 0;
(void)ac;

while (1)
{
	input = read_input();

	if (input == NULL)
	{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	return (status);
	}
	idx++;

	cmd = tokenize_input(input);
	if (!cmd)
		continue;

	if (check_builtin(cmd[0]))
	builtinhandle(cmd, av, &status, idx);
	else
		status = execute_cmd(cmd, av, idx);
}
}
