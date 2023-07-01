#include "shell.h"

int main()
{
	char input[MAX_COMMAND_LENGTH];
	int status;

	do
	{
		display_prompt();
		status = read_command(input);
		if (status)
		{
			execute_command(input);
		}
	}
	while (status);

	return (0);
}
