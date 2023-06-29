#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

#define MAX_INPUT_LENGTH 100
#define MAX_ARGUMENTS 10

void shell_loop(void) {
    char input[MAX_INPUT_LENGTH];
    char *arguments[MAX_ARGUMENTS];
    pid_t pid;
    int status;
    int argc;
    char *token;

    while (1) {
        printf("#cisfun$ ");
        if (fgets(input, sizeof(input), stdin) == NULL)
            break;

        input[strcspn(input, "\n")] = '\0'; /* Remove trailing newline */

        if (strcmp(input, "exit") == 0)
            break;

        argc = 0;
        token = strtok(input, " ");

        while (token != NULL && argc < MAX_ARGUMENTS - 1) {
            arguments[argc++] = token;
            token = strtok(NULL, " ");
        }
        arguments[argc] = NULL;

        pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            if (execvp(arguments[0], arguments) == -1) {
                char *path = getenv("PATH");
                char *path_token = strtok(path, ":");

                while (path_token != NULL) {
                    char *command = malloc(strlen(path_token) + strlen(arguments[0]) + 2);
                    sprintf(command, "%s/%s", path_token, arguments[0]);
                    execvp(command, arguments);
                    free(command);
                    path_token = strtok(NULL, ":");
                }
            perror(arguments[0]);
            exit(EXIT_FAILURE);
	    }
        } else {
            waitpid(pid, &status, 0);
        }
    }
}
