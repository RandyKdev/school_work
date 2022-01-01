#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_LINE 80
#define MAX_ARGS MAX_LINE / 2 + 1

void get_next_argument(char *input, char *args[], char argc) {
    char *buffer;
    buffer = strtok(input, " ");
   
    if (buffer == NULL) {
        args[argc] = NULL;
    } else {
        args[argc] = (char *) malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(args[argc], buffer);
    }
}

void split_user_input(char *input, char *args[]) {
    char *buffer;
    int argc = 0;

    get_next_argument(input, args, argc);

    while (args[argc] != NULL && argc < MAX_ARGS) {
        get_next_argument(NULL, args, ++argc);
    }

    // removing the '\n' at the last argument
    if (args[--argc] != NULL) {
        args[argc][strlen(args[argc]) - 1] = '\0';
    }
}

void read_user_input(char *args[]) {
    char input[MAX_LINE + 1];

    fgets(input, MAX_LINE, stdin);
    fflush(stdin);

    split_user_input(input, args);
}

bool ends_with_ampersand(char *args[]) {
    int i;
    for (i = 0; args[i] != NULL && i < MAX_ARGS; i++);

    if (strcmp(args[--i], "&") == 0) {
        return true;
    }

    return false;
}

void execute_command_in_child_process(char *args[]) {
    pid_t child_state = fork();

    if (child_state == 0) {
        execvp(args[0], args);
    } else if (child_state == -1) {
        printf("Child process couldn't be created\n");
    } else {
        if (!ends_with_ampersand(args)) {
            wait(NULL);
        }
    }
}

int main(void) {
    char *args[MAX_ARGS];
    int should_run = 1;

    while (should_run) {
        printf("osh> ");
        fflush(stdout);

        read_user_input(args);

        execute_command_in_child_process(args);

        should_run = 0;
    }

    return 0;
}