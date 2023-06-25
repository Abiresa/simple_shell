#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/*
 * print_prompt -  Prints the shell prompt.
 *
 */

void print_prompt()
{
	printf("Shell> ");
}

/*
 * read_input - Reads input from the user and returns the input string.
 *
 */

char *read_input()
{
	char *input = NULL;
	size_t buffer_size = 0;
	getline(&input, &buffer_size, stdin); /* Read input form the user */

	size_t input_length = strlen(input); /* Remove trailing newline character */
	if (input[input_length - 1] == '\n')
	{
		input[input_length - 1] = '\0';
	}

	return (input);
}

/*
 * **parse_input - tokenizes the input string into an array of tokens, separated by delimiters (whitespace characters).
 * @input: The input string.
 */

char **parse_input(char *input)
{
	const char *delimiters = " \t\r\n\a";
	const int token_buffer_size = 64;
	int token_count = 0;

	char **tokens = malloc(token_buffer_size * sizeof(char *));
	if (tokens == NULL)
	{
		fprintf(stderr, "Allocation error\n");
		exit(EXIT_FAILURE);
	}

	char *token = strtok(input, delimiters); /* Tokenize the input string */
	while (token != NULL)
	{
		tokens[token_count] = token;
		token_count++;

		if (token_count >= token_buffer_size)
		{
			token_buffer_size += token_buffer_size;
			tokens = realloc(tokens, token_buffer_size * sizeof(char *));
			if (tokens == NULL)
			{
				fprintf(stderr, "Reallocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, delimiters);
	}
	tokens[token_count] = NULL;

	return (tokens);
}
