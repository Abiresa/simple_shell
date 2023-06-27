#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * execute_command - Execute a command with arguments.
 * @input: The command input string.
 */

void execute_command(char *input)
{
	/* Process ID variable, and Status of the child process */
	pid_t pid;
	int status;

	/* Create a child process */

	pid = fork();
	if (pid < 0)
	{
		perror("Forking child process failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/* Child process */
		char **arguments = parse_input(input, NULL);

		if (execvp(arguments[0], arguments) == -1)
		{
			perror("Execution failed");
			exit(EXIT_FAILURE);
		}
		else
		{
			/* Parent process */
			do
			{
				pid_t wpid = waitpid(pid, &status, WUNTRACED);
				if (wpid == -1)
				{
					perror("Waiting for child process failed");
					exit(EXIT_FAILURE);
				}
			}
			while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
	}
}
