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

void reset_arr(char *arr[]) {
    int i = 0;
    while(arr[i] != NULL && i < MAX_ARGS) {
        free(arr[i]);
        arr[i] = NULL;
        i++;
    }
}

void split_user_input(char *input, char *args[]) {
    char *buffer;
    int argc = 0;

    // reset args array, frees all used memory locations
    reset_arr(args);

    // fills args withs args from user
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

int ends_with_ampersand(char *args[]) {
    int i;
    for (i = 0; args[i] != NULL && i < MAX_ARGS; i++);

    if (strcmp(args[--i], "&") == 0) {
        return i;
    }

    return 0;
}

bool is_history_command(char *args[]) {
    return strcmp(args[0], "!") == 0 && strcmp(args[1], "!") == 0 && args[2] == NULL;
}

void print_arr(char *arr[]) {
    printf("osh> ");
    int i  = 0;
    while(arr[i] != NULL && i < MAX_ARGS) {
        printf("%s ", arr[i]);
        i++;
    }
    printf("\n");
}

void copy_arr(char *dest[], char *src[]) {
    int i = 0;
    while(src[i] != NULL && i < MAX_ARGS) {
        dest[i] = (char *) malloc((strlen(src[i]) + 1) * sizeof(char));
        strcpy(dest[i], src[i]);
        i++;
    }
}

void prepare_history_command(char *args[], char *history[]) {
    // prints previous command
    print_arr(history);

    // frees "!" in args
    free(args[0]);
    free(args[1]);
    args[0] = NULL;
    args[1] = NULL;
            
    // copies command in history to args
    copy_arr(args, history);
}

void execute_command_in_child_process(char *args[], char *history[]) {
    if(is_history_command(args)) {
        puts("history command");
        prepare_history_command(args, history);
    }

    int ampersand_location = ends_with_ampersand(args);
    if(ampersand_location) {
        puts("ampersand found");
        free(args[ampersand_location]);
        args[ampersand_location] = NULL;
    }

    pid_t child_state = fork();
    
    if (child_state == 0) {
        execvp(args[0], args);
    } else if (child_state == -1) {
        printf("Child process couldn't be created\n");
    } else {
       
        if (!ampersand_location) {
             printf("%d\n", ampersand_location);
            wait(NULL);
        }

        reset_arr(history);
        copy_arr(history, args);

        if(ampersand_location) {
            history[ampersand_location] = (char *) malloc(2 * sizeof(char));
            strcpy(history[ampersand_location], "&");
        }
    }
}

int main(void) {
    char *args[MAX_ARGS] = {NULL};
    char *history[MAX_ARGS] = {NULL};
    int should_run = 1;

    while (should_run) {
        printf("osh> ");
        fflush(stdout);

        read_user_input(args);

        execute_command_in_child_process(args, history);

        // should_run = 0;
    }

    return 0;
}