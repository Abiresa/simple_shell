#ifndef SHELL_H
#define SHELL_H

#define MAX_COMMAND_LENGTH 1024

void display_prompt();
int read_command(char *input);
void execute_command(char *command);

#endif
