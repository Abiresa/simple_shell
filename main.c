#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

#define MAX_INPUT_LENGTH 100

/*
 * main - Sets up a loop that continuously prompts for user input with the ">> " prompt.
 */

int main()
{
	/* Initialize the shell */
	char input[MAX_INPUT_LENGTH];

	while (1)
	{
		printf(">> ");
		fgets(input, MAX_INPUT_LENGTH, stdin);

		input[strcspn(input, "\n")] = '\0';

		/* Parse and execute commands */
		execute_command(char *input);
	}
	return (0);
}
