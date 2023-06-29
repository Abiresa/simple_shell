#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

#define MAX_ARGUMENTS 100
#define MAX_INPUT_LENGTH 1000

/*
 * read_input - Reads input from the user and returns the input string.
 *
 * Returns the input as a string.
 */

char *read_input()
{
	size_t input_length;
	char *input = malloc(MAX_INPUT_LENGTH * sizeof(char));

	if (input == NULL)
	{
		fprintf(stderr, "Error: Failed to allocate memory for input\n");
		exit(EXIT_FAILURE);
	}

	printf("$ ");

	if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL)
	{
		free(input);
		return (NULL);
	}

	input_length = strlen(input);
	if (input_length > 0 && input[input_length - 1] == '\n')
	{
		input[input_length - 1] = '\0';
	}
	return (input);
}

/*
 * **parse_input - Takes the input string and tokenizes
 * it using whitespace characters as delimiters.
 * Description: - Use 'strtok()' to split the input into
 * individual tokens and stores them in an array.
 *              - Keeps track of the number of arguments ('argc')
 * and sets the elements of the array to NULL (required by function
 * 'execvp()').
 */

char **parse_input(char *input, int *argc)
{
	const char *delimiters = " \t\n";
	char *token;
	char **arguments = malloc(MAX_ARGUMENTS * sizeof(char *));
	int i = 0;

	if (arguments == NULL)
	{
		fprintf(stderr, "Error: Failed to allocate memory for arguments\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(input, delimiters); /* Tokenize the input string */
	while (token != NULL)
	{
		arguments[i] = token;
		i++;

		if i >= MAX_ARGUMENTS :
		{
			 fprintf(stderr, "Error: Too many arguments\n");
			 free(arguments);
			 exit(EXIT_FAILURE);
		}

		token = strtok(NULL, delimiters);
	}
	arguments[i] = NULL;

	*argc = i;

	return (arguments);
}
