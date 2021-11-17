/**
 * @file 
 * @brief A Queue implementation using array
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
 * @brief Returns the number of elements in the queue
 * @returns the number of elements in the queue
 */
int sizeOfQueue(struct node *queue) {
    int size;
    for(size = 0; queue != NULL; queue = queue->next, size++);
    return size;
}

/**
 * @brief Checks if the queue is empty
 * @returns true if the queue is empty
 * @returns false if the queue is not empty
 */
bool queueIsEmpty(struct node *queue) {
    return queue == NULL;
}

/**
 * @brief Creates a queue of a particular size
 * @param size the size of the queue to be created
 * @returns NULL if there is not memory available to create the queue
 * @returns the pointer to newly created queue of `size`
 */
struct node* createNode() {
    struct node *node = (struct node *) malloc(sizeof(struct node));
    
    if(node == NULL) {
        printf("No memory available, could not create queue \n");
        exit(EXIT_FAILURE);
    }

    return node;
}

void insertNode(struct node *queue, struct node *newNode) {
    if(queue->next == NULL) {
        queue->next = newNode;
        return;
    }

    insertNode(queue->next, newNode);
}

/**
 * @brief Inserts an element at the end of the queue
 * @param queue the pointer to the queue
 * @param element the element to be inserted in to the queue
 * @returns void
 */
struct node* enqueue(struct node *queue, int data) {
    struct node *newNode = createNode();
    newNode->data = data;
    newNode->next = NULL;
    if(queue == NULL) return newNode;
    insertNode(queue, newNode);
    return queue;
}



/**
 * @brief Returns and removes the element at the head of the queue
 * @param queue the pointer to the queue
 * @returns NULL if queue is empty
 * @returns the element at the head of the queue if it is not empty
 */
int dequeue(struct node **queue) {
    if(queueIsEmpty(*queue)) {
        printf("Underflow error: Queue is empty \n"); 
    } else {
        int data = (*queue)->data;
        struct node *tmp = (*queue)->next;
        free((*queue));
        (*queue) = tmp;
        return data;
    }
}

/**
 * @brief Displays the content of the queue
 * @param queue the pointer to the queue
 * @returns void
 */
void display(struct node *queue) {
    if(queueIsEmpty(queue)) {
        printf("Queue is empty \n");
        return;
    }

    printf("Queue contents: ");
    printf("HEAD -> ");
    while(queue != NULL) {
        printf("%d ", queue->data);
        queue = queue->next;
    }
    printf(" <- TAIL\n");
}

/**
 * @brief Returns the element at the head of queue without removing it
 * @param queue the pointer to the queue 
 * @returns NULL if the queue is empty
 * @returns The element at the head of the queue if it is not empty
 */
int headOfQueue(struct node *queue) {
    if(queueIsEmpty(queue)) {
        printf("Queue is empty \n");
    } else {
        return queue->data;
    }
}

/**
 * @brief Returns the element at the end of queue without removing it
 * @param queue the pointer to the queue 
 * @returns NULL if the queue is empty
 * @returns The element at the end of the queue if it is not empty
 */
int endOfQueue(struct node *queue) {
    if(queueIsEmpty(queue)) {
        printf("Queue is empty \n");
    } else {
        while(queue->next != NULL) {
            queue = queue->next;
        }

        return queue->data;
    }
}

/**
 * @brief Self-test Implementations
 * @returns void
 */
void test(void) {
    // The following lines tests the program for correct behaviour
    struct node *queue = NULL;

    assert(queueIsEmpty(queue) == true);

    queue = enqueue(queue, -1); // inserts -1 in to the queue
    queue = enqueue(queue, 5); // inserts 5 in to the queue
    queue = enqueue(queue, 2); // inserts 2 in to the queue

    assert(sizeOfQueue(queue) == 3); // checks if there are 3 elements in queue
    
    queue = enqueue(queue, 10); // inserts 10 in to the queue
    queue = enqueue(queue, 35); // inserts 35 in to the queue
    
    assert(sizeOfQueue(queue) == 5); // checks if there are 5 elements in queue
    display(queue); // print content of queue

    assert(headOfQueue(queue) == -1); // checks if element at head of queue is -1
    assert(dequeue(&queue) == -1); // checks if dequeue returns -1
    
    assert(headOfQueue(queue) == 5); // checks if element at head of queue is 5
    assert(dequeue(&queue) == 5); // checks if dequeue returns 5

    assert(endOfQueue(queue) == 35); // checks if element at end of queue is 35
    queue = enqueue(queue, 40); // inserts 40 in to the queue
    assert(endOfQueue(queue) == 40); // checks if element at end of queue is 40

    assert(queueIsEmpty(queue) == false); // checks if queue is not empty
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
