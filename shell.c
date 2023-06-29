#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

/*
 * execute_command - Executing a given command.
 */

void execute_command(char *input)
{
	int argc;
	char **arguments = parse_input(input, &argc);

	if (arguments == NULL || arguments[0] == NULL)
	{
		free(arguments);
		return;
	}

	if (is_builtin_command(arguments[0]))
	{
		handle_builtin_command(arguments[0], arguments);
	}
	else
	{
		create_child_process(arguments);
	}

	free(arguments);
}

/*
 * handle_builtin_command - Handles built-in commands.
 */

void handle_builtin_command(char *command, char **arguments)
{
	/*	Implement the logic for each built-in command	*/
	if (strcmp(command, "cd") == 0)
	{
		if (arguments[1] == NULL) /* Change directory */
		{
			chdir(getenv("HOME"));
		}
		else
		{
			if (chdir(arguments[1]) != 0)
			{
				perror("chdir");
			}
		}
	}
	else if (strcmp(command, "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
}

/*
 * create_child_process - Creates a child process
 * and executes the command within that process.
 */

void create_child_process(char *command, char **arguments)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execvp(arguments[0], arguments) == -1)
		{
			perror("execvp");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
	}
}

int is_builtin_command(char *command)
{
	return (strcmp(command, "cd") == 0 || strcmp(command, "exit") == 0);
}
