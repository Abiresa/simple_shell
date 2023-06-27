#ifndef SHELL_H
#define SHELL_H

#define MAX_ARGUMENTS 100

void execute_command(char *input);
int is_builtin_command(char *input);
void handle_builtin_command(char *command, char **arguments);
void create_child_process(char *command, char **arguments);
char **parse_input(char *input, int *argc);
void print_prompt();
char *read_input();
void shell_loop();

#endif /* SHELL_H */
