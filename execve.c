#include "shell.h"
/**
 * execute_cmd - a function that executes a command using system calls
 * @cmd: an array of strings representing the command and its args.
 * @arv: an array of strings representing the command-line arguments.
 * @indx: the index of the command in the command list.
 * Return: the exit status of the executed command
*/
int execute_cmd(char **cmd, char **arv, int indx)
{
	char *lastcmd;
	pid_t pid;
	int status;

	lastcmd = path_handle(cmd[0]);
	if (!lastcmd)
	{
		printmsg_error(arv[0], cmd[0], indx);
		cleanup_mem(cmd);
		return (127);
	}

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
	{
		if (execve(lastcmd, cmd, environ) == -1)
		{
			free(lastcmd);
			cleanup_mem(cmd);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		cleanup_mem(cmd);
		free(lastcmd);
	}

	return (WEXITSTATUS(status));
}
