#include "shell.h"

int main()
{
	int argc;
	char input[MAX_COMMAND_LENGTH];
	char *args[MAX_ARGS];

	while (1)
	{
		/* Display the shell prompt */
		printf("#cisfun$ ");
		fflush(stdout);

			/* Read the input command */
			if (fgets(input, sizeof(input), stdin) == NULL)
			{
				break; /* Exit the loop on EOF */
			}

		/* Tokenize the input command */
		argc = 0;
		tokenize_input(input, args, &argc);

		/* Check for built-in commands */

		if (argc > 0 && strcmp(args[0], "exit") == 0)
		{
			break; /* Exit the shell on "exit" command */
		}
		else if (argc > 0 && strcmp(args[0], "cd") == 0)
		{
			if (argc > 1)
			{
				if (chdir(args[1]) != 0)
				{
					perror("cd error");
				}
			}
			continue; /* Skip executing the command after "cd" */
		}

		/* Execute the command */
		execute_command(args);
	}

	return (0);
}
