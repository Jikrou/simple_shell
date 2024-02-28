#include "shell.h"
/**
 * display_prompt - the function display a prompt on the standard
 * output if the standard input is a terminal
 * Return: 0 on success
*/
int display_prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	return (0);
}
