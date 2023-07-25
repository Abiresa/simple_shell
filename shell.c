#include "shell.h"

/**
 * main - Main function for the shell program.
 * @argc: The number of arguments passed to the program.
 * @argv: Array of strings containing the arguments.
 * @envp: Array of strings containing the environment variables.
 *
 * Return: The exit status of the shell program.
 */

int main(int argc, char **argv, char **envp)
{
	char *command_line = NULL, **parsed_command = NULL;
	int path_value = 0, exit_status = 0, command_found = 0;
	(void)argc;

	while (1)
	{
		command_line = read_user_input();
		if (command_line)
		{
			path_value++;
			parse_command = tokenize_input(command_line);
			if (!parsed_command)
			{
				free(command_line);
				continue;
			}
			if ((!_strcmp(parsed_command[0], "exit")) && parsed_command[1] == NULL)
				exit_shell(parsed_command, command_line, exit_status);
			if (!_strcmp(parsed_command[0], "env"))
				print_environment(envp);
			else
			{
				command_found = find_command_in_path(&parsed_command[0], envp);
				exit_status = execute_child_process(parsed_command, argv, envp, command_line, path_value, command_found);
				if (command_found == 0)
					free(parsed_command[0]);
			}
			free(parsed_command);
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(exit_stattus);
		}
		free(command_line);
	}
	return (exit_status);
}
