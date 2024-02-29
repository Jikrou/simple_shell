#include "shell.h"
/**
 * main - this is the entry point of the program? It call the shell_mode
 * function to enter inter-mode to process commands
 * @argc: the number og command-line arguments.
 * @argv: an array of strings representing the arguments
 * Return: 0on successful execution
*/
int main(int argc, char **argv)
{
	shell_mode(argc, argv);
	return (0);
}
