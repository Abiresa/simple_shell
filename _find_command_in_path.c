#include "shell.h"

/**
 * _find_command_in_path - Search for the command in "PATH" environment variable.
 * @command: Pointer provided by the user.
 * @env: Pointer to the environment variables array.
 *
 * Return: 0 if found and updated, -1 otherwise.
 */

int _find_command_in_path(char **command, char **env)
{
	char *token = NULL, *path_env = NULL, *absolute_path = NULL;
	size_t command_length, path_length;
	struct stat stat_buffer;

	if (stat(*command, &stat_buffer) == 0)
		return (-1);

	path_env = _get_path(env);
	if (!path_env)
		return (-1);

	token = _strtok(path_env, ":");
	command_length = _strlen(*command);

	while (token)
	{
		path_length = _strlen(token);
		absolute_path = malloc(sizeof(char) * (path_length + command_length + 2));
		if (!absolute_path)
		{
			free(path_env);
			return (-1);
		}

		absolute_path = _strcpy(absolute_path, token);
		_strcat(absolute_path, "/");
		_strcat(absolute_path, *command);

		if (stat(absolute_path, &stat_buffer) == 0)
		{
			*command = absolute_path;
			free(path_env);
			return (0);
		}

		free(absolute_path);
		token = _strtok(NULL, ":");
	}

	free(path_env);
	return (-1);
}
