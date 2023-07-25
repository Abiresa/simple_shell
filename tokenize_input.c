#include "shell.h"

/**
 * tokenize_input - Tokenize a string into an array of strings.
 * @input: Pointer to be tokenized.
 *
 * Return: Pointer to an array of strings or NULL.
 */

char **tokenize_input(char *input)
{
	char **tokens_array = NULL;
	char *token = NULL;
	size_t num_tokens = 0;
	int array_size = 0;

	if (input == NULL)
		return (NULL);
	for (num_tokens = 0; input[num_tokens]; num_tokens++)
	{
		if (input[num_tokens] == ' ')
			array_size++;
	}

	if ((array_size + 1) == _strlen(input))
		return (NULL);

	tokens_array = malloc(sizeof(char *) * (array_size + 2));
	if (tokens_array == NULL)
		return (NULL);
	token = _strtok(input, " \n\t\r");
	for (num_tokens = 0; token != NULL; num_tokens++)
	{
		tokens_array[num_tokens] = token;
		token = _strtok(NULL, " \n\t\r");
	}

	tokens_array[num_tokens] = NULL;
	return (tokens_array);
}
