#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

#define MAX_INPUT_LENGTH 100

void shell_loop(void) {
    char input[MAX_INPUT_LENGTH];
    pid_t pid;
    int status;

    while (1) {
        printf("#cisfun$ ");
        if (fgets(input, sizeof(input), stdin) == NULL)
            break;

        input[strcspn(input, "\n")] = '\0'; /* Remove trailing newline */

        if (strcmp(input, "exit") == 0)
            break;

        pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            execlp(input, input, (char *)NULL);
            perror(input);
            exit(EXIT_FAILURE);
        } else {
            waitpid(pid, &status, 0);
        }
    }
}
