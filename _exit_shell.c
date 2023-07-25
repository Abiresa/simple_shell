#include "shell.h"

/**
 * exit_shell - Close the simple shell.
 * @arguments: Pointer to the argument array.
 * @command_line: Pointer to string.
 * @exit_code: The exit code.
 *
 * Return: None.
 */

void exit_shell(char **arguments, char *command_line, int exit_code)
{
	int status = 0;

	if (!arguments[1])
	{
		free(command_line);
		free(arguments);
		exit(exit_code);
	}

	status = atoi(arguments[1]);

	free(command_line);
	free(arguments);
	exit(status);
}

/**
 * print_environment - Print all environment variables.
 * @environment: Pointer to the environment variables array.
 *
 * Return: None.
 */

void print_environment(char **environment)
{
	size_t index = 0;

	while (environment[index])
	{
		write(STDOUT_FILENO, environment[index], _strlen(environment[index]));
		write(STDOUT_FILENO, "\n", 1);
		index++;
	}
}
