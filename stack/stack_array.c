#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

int HEAD = 0;

int *create(int size);
int sizeOfStack(int *stack);
int pop(int *stack);
void push(int *stack, int element);
int topOfStack(int *stack);
bool stackIsEmpty(int *stack);
bool stackIsFull(int *stack);
void display(int *stack);

void test(void) {
    int size = 5;
    int *stack = create(size);
    assert(sizeOfStack(stack) == size);
    assert(stackIsEmpty == true);

    push(stack, -1);
    push(stack, 5);
    push(stack, 2);
    push(stack, 10);
    push(stack, 35);

    assert(stackIsFull(stack) == true);

    push(stack, 50);
    assert(topOfStack(stack) == 35);

    assert(pop(stack) == 2);
    assert(topOfStack(stack) == 5);
    assert(pop(stack) == 5);

    assert(stackIsEmpty(stack) == false);

    free(stack);

}

int main(void) {

    // This is to test the implementation
    test();

    int size;
    printf("Enter the size of stack: ");
    scanf("%d", &size);
    int *stack = create(size);

    free(stack);
    return 0;
}

int *create(int size) {
    int *stack = (int *) malloc(sizeof(int) * size);
    return stack;
}

int sizeOfStack(int *stack) {
    return sizeof(stack) / sizeof(stack[0]);
}

int pop(int *stack) {
    if(stackIsEmpty(stack)) {
        printf("Underflow Error: The stack is empty \n");
        return;
    }

    return stack[--HEAD];
}

void push(int *stack, int element) {
    if(stackIsFull(stack)) {
        printf("Overflow Error: The stack is full \n");   
        return;
    }

    stack[HEAD++] = element;
}

int topOfStack(int *stack) {
    if(stackIsEmpty(stack)) {
        printf("Underflow Error: The stack is empty \n");  
        return;
    }

    return stack[HEAD - 1];
}

void display(int *stack) {
    printf("Stack contents: ");
    for(int i = 0; i < HEAD; i++) {
        printf(" %d", stack[i]);
    }
    printf("<- HEAD \n");
}

bool stackIsEmpty(int *stack) {
    return HEAD == 0;
}

bool stackIsFull(int *stack) {
    return HEAD > sizeOfStack(stack);
}
