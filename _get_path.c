#include "shell.h"

/**
 * _get_path - Get the value of the "PATH" environment variable.
 * @env: Pointer to the environement variables array.
 *
 * Return: Pointer to the value of "PATH" or NULL if not found.
 */

char *_get_path(char **env)
{
	size_t index = 0, path_start = 0, path_length = 5;
	char *path = NULL;

	for (index = 0; _strncmp(env[index], "PATH=", 5); index++);

	if (env[index] == NULL)
		return (NULL);

	for (path_length = 5; env[index][path_length]; path_length++);
	path = malloc(sizeof(char) * (path_length + 1));

	if (path == NULL)
		return (NULL);

	for (path_start = 5, path_length = 0; env[index][path_start]; path_start++, path_length++) path[path_length] = env[index][path_start];

	path[path_length] = '\0';
	return (path);
}
