#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 10

/*Function to tokenize the input command into arguments */
int tokenize_input(char *input, char **args, int *argc)
{
	char *token = strtok(input, " \t\n");
	while (token != NULL && *argc < MAX_ARGS - 1)
	{
		args[*argc++] = token;
		token = strtok(NULL, " \t\n");
	}

	args[*argc] = NULL;
	return (*argc);
}

/* Function to execute the command */
void execute_command(char **args)
{
	pid_t pid = fork();
	if (pid < 0)
	{
		perror("fork error");
	}
	else if (pid == 0)
	{
		/* Child process */
		if (execvp(args[0], args) < 0)
		{
			perror("execvp error");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process */
		int status;
		waitpid(pid, &status, 0);
	}
}
