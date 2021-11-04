/**
 * @file 
 * @brief A Queue implementation using circular array
 */

#include <stdio.h> // for IO operations
#include <stdbool.h> // for bool data type
#include <assert.h> // for assert function (for tests)
#include <stdlib.h> // for the malloc and free functions

int HEAD = 0; // The index of the head of queue
int END = -1; // The index of the end of queue
int SIZE; // the total size of the queue

/**
 * @brief Returns the number of elements in the queue
 * @returns the number of elements in the queue
 */
int sizeOfQueue() {
    return END - HEAD + 1;
}

/**
 * @brief Checks if the queue is empty
 * @returns true if the queue is empty
 * @returns false if the queue is not empty
 */
bool queueIsEmpty(int *queue) {
    return HEAD > END;
}

/**
 * @brief Checks if the queue is full
 * @returns true if the queue is full
 * @returns false if the queue is not full
 */
bool queueIsFull(int *queue) {
    return sizeOfQueue() == SIZE;
}

/**
 * @brief Creates a queue of a particular size
 * @param size the size of the queue to be created
 * @returns NULL if there is not memory available to create the queue
 * @returns the pointer to newly created queue of `size`
 */
int *create(int size) {
    int *queue = (int *) malloc(sizeof(int) * size);
    
    if(queue == NULL) {
        printf("No memory available, could not create queue \n");
        return NULL;
    }

    return queue;
}

/**
 * @brief Inserts an element at the end of the queue
 * @param queue the pointer to the queue
 * @param element the element to be inserted in to the queue
 * @returns void
 */
void enqueue(int *queue, int element) {
    if(queueIsFull(queue)) {
        printf("Overflow error: Queue is full \n");
        return;
    }

    queue[(++END) % SIZE] = element;
}

/**
 * @brief Returns and removes the element at the head of the queue
 * @param queue the pointer to the queue
 * @returns NULL if queue is empty
 * @returns the element at the head of the queue if it is not empty
 */
int dequeue(int *queue) {
    if(queueIsEmpty(queue)) {
        printf("Underflow error: Queue is empty \n"); 
    } else {
        return queue[(HEAD++) % SIZE];
    }
}

/**
 * @brief Displays the content of the queue
 * @param queue the pointer to the queue
 * @returns void
 */
void display(int *queue) {
    if(queueIsEmpty(queue)) {
        printf("Queue is empty \n");
        return;
    }

    printf("Queue contents: ");
    for(int i = END; i >= HEAD; i--) {
        printf("%d ", queue[i % SIZE]);
    }
    printf(" <- HEAD \n");
}

/**
 * @brief Returns the element at the head of queue without removing it
 * @param queue the pointer to the queue 
 * @returns NULL if the queue is empty
 * @returns The element at the head of the queue if it is not empty
 */
int headOfQueue(int *queue) {
    if(queueIsEmpty(queue)) {
        printf("Queue is empty \n");
    } else {
        return queue[HEAD % SIZE];
    }
}

/**
 * @brief Returns the element at the end of queue without removing it
 * @param queue the pointer to the queue 
 * @returns NULL if the queue is empty
 * @returns The element at the end of the queue if it is not empty
 */
int endOfQueue(int *queue) {
    if(queueIsEmpty(queue)) {
        printf("Queue is empty \n");
    } else {
        return queue[END % SIZE];
    }
}

/**
 * @brief Self-test Implementations
 * @returns void
 */
void test(void) {
     // The following lines tests the program for correct behaviour
    SIZE = 5;
    int *queue = create(SIZE); // Creates queue of size 5

    assert(sizeOfQueue() == 0); // checks if the queue has no elements
    assert(queueIsEmpty(queue) == true); // checks if the queue is empty

    enqueue(queue, -1); // inserts -1 in to the queue
    enqueue(queue, 5); // inserts 5 in to the queue
    enqueue(queue, 2); // inserts 2 in to the queue

    assert(sizeOfQueue() == 3); // checks if there are 3 elements in queue
    
    enqueue(queue, 10); // inserts 10 in to the queue
    enqueue(queue, 35); // inserts 35 in to the queue
    
    assert(sizeOfQueue() == 5); // checks if there are 5 elements in queue
    display(queue); // print content of queue

    assert(queueIsFull(queue) == true); // checks if queue is full

    assert(headOfQueue(queue) == -1); // checks if element at head of queue is -1
    assert(dequeue(queue) == -1); // checks if dequeue returns -1
    
    assert(headOfQueue(queue) == 5); // checks if element at head of queue is 5
    assert(dequeue(queue) == 5); // checks if dequeue returns 5

    assert(endOfQueue(queue) == 35); // checks if element at end of queue is 35
    enqueue(queue, 40); // inserts 40 in to the queue
    assert(endOfQueue(queue) == 40); // checks if element at end of queue is 40

    assert(queueIsEmpty(queue) == false); // checks if queue is not empty
    assert(sizeOfQueue() == 4); // checks if there are 4 elements in queue
    display(queue); // print content of queue

    free(queue); // de-allocates memory given to queue
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main(void) {
    test(); // runs self-test implementation of the program
    return 0;
}
