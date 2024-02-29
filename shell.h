#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define DELIM " \t\n"
extern char **environ;

char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
void rev_string(char *s, int len);
char *_itao(int m);

int shell_mode(int ac, char **av);
int display_prompt(void);
char *read_input(void);
char **tokenize_input(char *input);
int execute_cmd(char **cmd, char **arv, int indx);
char *_getenv(char *var);
char *path_handle(char *cmd);
void cleanup_mem(char **str);
void printmsg_error(char *name, char *comand, int indx);
void print_env(char **cmd, int *status);
void exit_(char **cmd, int *status);
void builtinhandle(char **cmd, char **av, int *status, int idx);
int check_builtin(char *cmd);
#endif

