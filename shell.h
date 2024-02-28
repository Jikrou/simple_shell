#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#define DELIM " \t\n"
extern char **environ;

char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strdup(char *str);
int shell_mode(int ac, char **av);
int display_prompt(void);
char *read_input(void);
char **tokenize_input(char *input);
int execute_cmd(char **cmd, char **arv);
void cleanup_mem(char **str);

#endif

