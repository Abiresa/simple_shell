#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * execute_command - Execute a command with arguments.
 * @args: The array of arguments.
 */

void execute_command(char **args)
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
		if (execvp(args[0], args) == -1)
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
