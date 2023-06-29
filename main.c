#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

int main(void)
{
	shell_loop();

	return (EXIT_SUCCESS);
}

void shell_loop()
{
	char *input;
	int status = 1;

	while (status)
	{
		printf("$ ");
		input = read_input();

		if (input != NULL)
		{
			execute_command(input);
			free(input);
		}
	}
}
