#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

#define MAX_INPUT_LENGTH 1000
#define MAX_ARGUMENTS 100

char *read_input()
{
	size_t input_length = 0;
	char *input = malloc(MAX_INPUT_LENGTH * sizeof(char));

	if (input == NULL)
	{
		fprintf(stderr, "Error: Failed to allocate memory for input\n");
		exit(EXIT_FAILURE);
	}
	/* Print shell prompt */
	printf("$ ");
	if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL)
	{
		free(input);
		return (NULL);
	}
	/* Remove trailing newline character, if present */
	input_length = strlen(input);
	if (input_length > 0 && input[input_length - 1] == '\n')
	{
		input[input_length - 1] = '\0';
	}
	return (input);
}

char **parse_input(char *input, int *argc)
{
	const char *delimiter = " \t\n";
	char *token;
	char **arguments = malloc(MAX_ARGUMENTS * sizeof(char *));
	int i = 0;

	if (arguments == NULL)
	{
		fprintf(stderr, "Error: Failed to allocate memory for arguments\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(input, delimiter);
	while (token != NULL)
	{
		arguments[i] = token;
		i++;
		if (i >= MAX_ARGUMENTS)
		{
			fprintf(stderr, "Error: Too many arguments\n");
			free(arguments);
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, delimiter);
	}
	/* Set the last argument to NULL for execvp */
	arguments[i] = NULL;

	*argc = i;
	return (arguments);
}
