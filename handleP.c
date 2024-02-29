#include "shell.h"
/**
 * path_handle - a function that search the command in the direstories
 * listed in the PATH environment variable.
 * @cmd: the command to search for.
 * Return: the full path to the comma,d if found, otherwise NULL
*/
char *path_handle(char *cmd)
{
	char *var_path, *lastcmd, *fold;
	int i;
	struct stat fv;

	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &fv) == 0)
				return (_strdup(cmd));

			return (NULL);
		}
	}

	var_path = _getenv("PATH");
	if (!var_path)
		return (NULL);

	fold = strtok(var_path, ":");
	while (fold)
	{
		lastcmd = malloc(_strlen(fold) + _strlen(cmd) + 2);
		if (lastcmd)
		{
			_strcpy(lastcmd, fold);
			_strcat(lastcmd, "/");
			_strcat(lastcmd, cmd);
			if (stat(lastcmd, &fv) == 0)
			{
				free(var_path);
				return (lastcmd);
			}
			free(lastcmd);

			fold = strtok(NULL, ":");
		}
	}
	free(var_path);
	return (NULL);
}
