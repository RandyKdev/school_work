/**
 * @file
 * @brief A Stack implementation using linked list
 */

#include <stdio.h> // for IO operations
#include <stdbool.h> // for bool data type
#include <assert.h> // for assert function (for tests)
#include <stdlib.h> // for the malloc and free functions

/**
 * @brief Structure representing a node in a linked list
 * @details Contains two fields, the data and next field
 */
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

    printf("Stack contents: ");
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
    struct node *head = NULL;

    assert(stackIsEmpty(head) == true);
    
    head = push(head, 1);
    head = push(head, 2);
    head = push(head, 3);
    head = push(head, 4);
    head = push(head, 5);

    assert(stackIsEmpty(head) == false);

    assert(sizeOfStack(head) == 5);
    displayStack(head);

    assert(topOfStack(head) == 5);
    assert(pop(&head) == 5);
    displayStack(head);

    head = push(head, 6);
    displayStack(head);
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main(void) {
    test(); // runs self-test implementation of the program
    return 0;
}
