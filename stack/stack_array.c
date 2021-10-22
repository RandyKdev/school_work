#include <stdio.h>
#include <stdbool.h>

typedef enum {
    STACK_OVERFLOW = -1, 
    STACK_UNDERFLOW = -2, 
    SUCCESS = -3,
} Status;

int SIZE_OF_STACK;
int head = 0;

int pop(int *STACK) {
    if(stackIsEmpty()) return STACK_UNDERFLOW;
    return STACK[--head];
}

Status push(int *STACK, int element) {
    if(stackIsFull()) return STACK_OVERFLOW;
    STACK[head++] = element;
    return SUCCESS;
}

int topOfStack(int *STACK) {
    if(stackIsEmpty()) return STACK_UNDERFLOW;
    return STACK[head - 1];
}

bool stackIsEmpty() {
    return head == 0;
}

bool stackIsFull() {
    return head > SIZE_OF_STACK;
}

int main(void) {
    printf("Enter the size of stack: ");
    scanf("%d", &SIZE_OF_STACK);
    int STACK[SIZE_OF_STACK];

    while(true) {
        // do whatever operations necessary
    }

    return 0;
}