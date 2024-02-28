#include "shell.h"
/**
 * execute_cmd - a function that executes a command using system calls
 * @cmd: an array of strings representing the command and its args
 * @arv: an array of strings representing the command-line arguments
 * Return: the exit status of the executed command
*/
int execute_cmd(char **cmd, char **arv)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
	{
		if (execve(cmd[0], cmd, environ) == -1)
		{
			perror(arv[0]);
			cleanup_mem(cmd);
			exit(127);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		cleanup_mem(cmd);
	}

	return (WEXITSTATUS(status));
}
