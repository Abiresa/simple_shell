#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 10

int tokenize_input(char *input, char **args, int *argc);
void execute_command(char **args);

#endif /* SHELL_H */
