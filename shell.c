#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void display_prompt()
{
	printf("#cisfun$ ");
}

int read_command(char *input)
{
	if (fgets(input, MAX_COMMAND_LENGTH, stdin) == NULL)
	{
		return (0); /* End of file (Ctrl+D) condition */
	}

	/* Remove the newline character at the end of the input */
	input[strcspn(input, "\n")] = '\0';
	return (1);
}

void execute_command(char *command)
{
	pid_t pid = fork();
	if (pid == 0)
	{
		/* Child process */
		if (execlp(command, command, NULL) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		/* Forking error */
		perror("Error");
	}
	else
	{
		/* Parent process */
		int status;
		waitpid(pid, &status, 0);
	}
}
