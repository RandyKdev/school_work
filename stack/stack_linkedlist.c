/**
 * @file
 * @brief A Stack implementation using linked list
 */

#include <stdio.h> // for IO operations
#include <stdbool.h> // for bool data type
#include <assert.h> // for assert function (for tests)
#include <stdlib.h> // for the malloc and free functions

struct node {
    int data;
    struct node *next;
};

/**
 * @brief Returns the number of elements in the stack
 * @returns the number of elements in the stack
 */
int sizeOfStack(struct node *stack, int size) {
    if(stack == NULL) return size;
    return sizeOfStack(stack, size + 1);
}

/**
 * @brief Checks if the stack is empty
 * @returns true if the stack is empty
 * @returns false if the stack is not empty
 */
bool stackIsEmpty(struct node *stack) {
    return stack == NULL;
}

/**
 * @brief Creates a stack of a particular size
 * @param size the size of the stack to be created
 * @returns NULL if there is not memory available to create the stack
 * @returns the pointer to newly created stack of `size`
 */
struct node *createNode(int data) {
    struct node *node = (struct node *) malloc(sizeof(struct node));

    if(node == NULL) {
        printf("No memory available, could not create Stack \n");
        return NULL;
    }

    node->data = data;
        
    return node;
}

/**
 * @brief Returns and removes the element at the top stack
 * @param stack the pointer to the stack
 * @returns NULL if stack is empty
 * @returns the element at the top of the stack if it is not empty
 */
int pop(struct node *stack) {
    if(stackIsEmpty(stack)) {
        printf("Underflow Error: The stack is empty \n");
    } else {
        int data = stack->data;
        struct node* temp = stack->next;
        free(stack);
        return data;
    }
}

/**
 * @brief Inserts an element in to the stack
 * @param stack the pointer to the stack
 * @param element the element to be inserted in to the stack
 * @returns void
 */
struct node* push(struct node *stack, int data) {
    struct node *newNode = createNode(data);

    newNode->next = stack;
    return newNode;
}

/**
 * @brief Returns the element at the top of stack without removing it
 * @param stack the pointer to the stack 
 * @returns NULL if the stack is empty
 * @returns The element at the top of the stack if it is not empty
 */
int topOfStack(struct node *stack) {
    if(stackIsEmpty(stack)) {
        printf("Underflow Error: The stack is empty \n");  
    } else {
        return stack->data;
    }
}

/**
 * @brief Displays the content of the stack
 * @param stack the pointer to the stack 
 * @returns void
 */
void displayStack(struct node *stack) {
    if(stackIsEmpty(stack)) {
        printf("The Stack is empty \n");
        return;
    }

    printf("Stack contents:\n");
    printf("HEAD  ->  \n");
    displayNodes(stack);
}

void displayNodes(struct node *node) {
    if(node == NULL) {
        return;
    }

    printf("%d ", node->data);
    displayNode(node->next);
}

/**
 * @brief Self-test Implementations
 * @returns void
 */
void test(void) {
    // The following lines tests the program for correct behaviour
    SIZE = 5;
    int *stack = create(SIZE); // Creates stack of size 5

    assert(sizeOfStack() == 0); // checks if the stack has no elements
    assert(stackIsEmpty(stack) == true); // checks if the stack is empty

    push(stack, -1); // inserts -1 in to the stack
    push(stack, 5); // inserts 5 in to the stack
    push(stack, 2); // inserts 2 in to the stack

    assert(sizeOfStack() == 3); // checks if there are 3 elements in stack
    
    push(stack, 10); // inserts 10 in to the stack
    push(stack, 35); // inserts 35 in to the stack
    
    assert(sizeOfStack() == 5); // checks if there are 5 elements in stack
    display(stack); // print content of stack

    assert(stackIsFull(stack) == true); // checks if stack is full

    assert(topOfStack(stack) == 35); // checks if element at top of stack is 35
    assert(pop(stack) == 35); // checks if pop returns 35

    assert(topOfStack(stack) == 10); // checks if element at top of stack is 10
    assert(pop(stack) == 10); // checks if pop returns 10

    assert(stackIsEmpty(stack) == false); // checks if stack is not empty
    display(stack); // print content of stack

    free(stack); // de-allocates memory given to stack
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main(void) {
    test(); // runs self-test implementation of the program
    return 0;
}
