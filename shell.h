#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>


extern char **environ;

int _strcmp(char *S, char *Z);
int _strlen(char *s);
size_t _strncmp(char *S1, char *S2, size_t n);
char *strcpy(char *dst, char *src);
char *_strtok(char *str, const char *delim);
size_t _strcspn(const char *S1, const char *S2);
size_t _strspn(const char *S1, const char *S2);
char *_strchr(const char *s, int c);
char *_strcat(char *dst, char *src);

char *read_user_input(void);
char **tokenize_input(char *input);
void exit_shell(char **arguments, char *command_line, int exit_code);
void print_environment(char **environment);
int execute_child_process(char **arguments, char **program_name, char **environment, char *command_line, int process_id, int checker);

#endif /* SHELL_H */
