#include "shell.h"

/**
 * read_user_input - Read a line of input from the User.
 *
 * Return: Pointer of input by user or NULL on failure.
 */

char *read_user_input(void)
{
	char *line_buffer = NULL;
	size_t biffer_size = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "#cisfun$ ", 9);

	if (getline(&line_buffer, &buffer_size, stdin) == -1)
	{
		free(line_buffer);
		return (NULL);
	}
	
	return (line_buffer);
}
