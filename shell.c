#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "shell.h"

/*
 * execute_command - Executing a given command.
 */

void execute_command(char *command)
{
	/* Parse the command and its arguments */
	char *arguments[MAX_ARGUMENTS];
	int num_arguments = parse_arguments(command, arguments);

	/* Check if it's a built-in command and handle it */
	if (is_builtin_command(arguments[0]))
			{
			handle_builtin_command(arguments[0], arguments);
			}
			else
			{
				/* If it's not a built-in command, execute it as an external program using the exec family of functions */
				create_child_process(arguments[0], arguments);
			}
}

/*
 * handle_builtin_command - Handles built-in commands.
 */

void handle_builtin_command(char *command, char **arguments)
{

        /*  Implement the logic for each built-in command  */
	if (strcmp(command, "cd") == 0)
	{
		if (arguments[1] == NULL) /* Change directory */
		{
			chdir(getenv("HOME"));
		}
		else 
		{
			chdir(arguments[1]);
		}
		else if (strcmp(command, "exit") == 0)
		{
			exit(0);/* Exit the shell */
		}
		else
		{
			printf("Unknown command: %s\n", command);/* Unknown built-in command */
		}
}

/*
 * create_child_process - Creates a child process and executes the command within that process.
 */

void create_child_process(char *command, char **arguments)
{
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("fork");
		return;
	}
	/*  Create a child process using fork and execute the command  */
	else if (pid == 0)
	{
		execvp(command, arguments);
		perror("execvp");
		exit(1);
	}
	else
	{
		int status;
		waitpid(pid, &status, 0);
	}
}

/*
 * shell_loop - Represents the main loop of the shell.
 *
 * Description: It prompts the user for input, reads the input using the
 * 			- read_input() function, parses the input into arguments.
 * 			- parse_input() function, and then executes the command.
 * 			- execute() function. The loop continues until the status returned.
 * 			- execute()  is non-zero, indicating that the shell should keep running.
 */

void shell_loop()
{
	char *line;
	char **args;
	int status;

	do
	{
		printf("> ");
		line = read_input();
		args = parse_input(line);
		status = execute(args);

		free(line);
		free(args);
	}
	while (status);
}
