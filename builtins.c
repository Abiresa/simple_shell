#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

extern char **environ;

void builtin_env(void) {
    char **env = environ;
    while (*env != NULL) {
        printf("%s\n", *env);
        env++;
    }
}
