/**
 * @file
 * @brief A Stack implementation using linked list
 */

#include <stdio.h> // for IO operations
#include <stdbool.h> // for bool data type
#include <assert.h> // for assert function (for tests)
#include <stdlib.h> // for the malloc and free functions

// Node structure for linked list
struct node {
    int data;
    struct node *next;
};

/**
 * @brief Returns the number of elements in the stack
 * @returns the number of elements in the stack
 */
int sizeOfStack(struct node *stack) {
    int size;
    for(size = 0; stack != NULL; stack = stack->next, size++);
    
    return size;
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
        exit(EXIT_FAILURE);
    }

    return node;
}

/**
 * @brief Returns and removes the element at the top stack
 * @param stack the pointer to the stack
 * @returns NULL if stack is empty
 * @returns the element at the top of the stack if it is not empty
 */
int pop(struct node **stack) {
    if(stackIsEmpty(*stack)) {
        printf("Underflow Error: The stack is empty \n");
    } else {
        int data = (*stack)->data;
        struct node* temp = (*stack)->next;
        free(*stack);
        *stack = temp;
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

    newNode->data = data;
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
    printf("HEAD -> ");

    while(stack != NULL) {
        printf("%d ", stack->data);
        stack = stack->next;
    }

    printf("\n");
}


/**
 * @brief Self-test Implementations
 * @returns void
 */
void test(void) {
    // The following lines tests the program for correct behaviour
    struct node *head = NULL; // sets head pointer to NULL

    assert(stackIsEmpty(head) == true); // checks if stack is empty
    
    head = push(head, 1); // inserts 1 in to stack
    head = push(head, 2); // inserts 2 in to stack
    head = push(head, 3); // inserts 3 in to stack
    head = push(head, 4); // inserts 4 in to stack
    head = push(head, 5); // inserts 5 in to stack

    assert(stackIsEmpty(head) == false); // checks if stack is empty
    
    assert(sizeOfStack(head) == 5); // checks if there are 5 elements in stack
    displayStack(head); // display content of stack

    assert(topOfStack(head) == 5); // checks if the element at the top of the stack is 5
    assert(pop(&head) == 5); // pops element from the stack and checks if it is 5
    displayStack(head); // display content of stack

    head = push(head, 6); // inserts 6 in to stack
    displayStack(head); // display content of stack
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main(void) {
    test(); // runs self-test implementation of the program
    return 0;
}
