#include "shell.h"
/**
 * check_builtin - checks if a command is a built-in command.
 * @cmd: the command to check.
 * Return: 1 if the command is built-in, otherwise 0.
*/
int check_builtin(char *cmd)
{
	char *is_built[] = {
		"exit", "env", NULL
	};
	int i;

	for (i = 0; is_built[i]; i++)
	{
		if (_strcmp(cmd, is_built[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * builtinhandle - a function that handles built-in commands.
 * @cmd: the command to handle.
 * @av: the argument vector.
 * @status: a pointer to the exit status.
 * @idx: the index of the command
*/
void builtinhandle(char **cmd, char **av, int *status, int idx)
{
	(void) av;
	(void) idx;

	if (_strcmp(cmd[0], "exit") == 0)
		exit_(cmd, status);

	else if (_strcmp(cmd[0], "env") == 0)
		print_env(cmd, status);
}

/**
 * exit_ - a function that handles the 'exit' command.
 * @cmd: the command to handle.
 * @status: a pointer to the exit status
*/
void exit_(char **cmd, int *status)
{
	cleanup_mem(cmd);
	exit(*status);
}

/**
 * print_env - a function that handles the 'env' command
 * @cmd: the command to handle.
 * @status: a pointer to the exit status.
*/
void print_env(char **cmd, int *status)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	cleanup_mem(cmd);
	(*status) = 0;
}


