#include "shell.h"

/**
 * execute_child_process - Create a child process and execute a new program.
 * @arguments: Command and values.
 * @program_name: Name of the shell program.
 * @environment: The environment variables array.
 * @command_line: The command line by the user.
 * @process_id: The process ID of the shell.
 * @checker: Checker flag.
 *
 * Return: 0 on success or the child process exit status.
 */

int execute_child_process(char **arguments, char **program_name, char **environment, char *command_line, int process_id, int checker)
{
	pid_t child_pid;
	int status;
	char *error_format = "%s: %d: %s: not found\n";

	child_pid = fork();

	if (child_pid == 0)
	{
		if (execve(arguments[0], arguments, environment) == -1)
		{
			fprintf(stderr, error_format, program_name[0], process_id, arguments[0]);
			if (!checker)
				free(arguments[0]);
			free(arguments);
			free(command_line);
			exit(errno);
		}
	}
	else
	{
		wait(&status);

		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			return (WEXITSTATUS(status));
	}

	return (0);
}
