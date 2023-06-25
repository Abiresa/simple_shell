#ifndef SHELL_H
#define SHELL_H

void execute_command(char **);
void handle_builtin_command(char *command, char **arguments);
void create_child_process(char *command, char **arguments);
char **parse_input();
void print_prompt();
char *read_input();
void shell_loop();


struct Command
{
	char *name;
	char **arguments;
};

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

#endif /* SHELL_H */
