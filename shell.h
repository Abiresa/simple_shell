#ifndef SHELL_H
#define SHELL_H

void shell_loop(void);
char *read_input();
char **parse_input(char *input, int *argc);
void execute_command(char *input);
int is_builtin_command(char *command);
void handle_builtin_command(char *command, char **arguments);
void create_child_process(char **arguments);

#endif /* SHELL_H */
