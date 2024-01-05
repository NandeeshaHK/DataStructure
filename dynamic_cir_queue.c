#include <stdio.h>
#include <stdlib.h>

// Structure to represent the circular queue
typedef struct {
    int* array;       // Dynamic array to store elements
    int capacity;     // Maximum capacity of the queue
    int front, rear;  // Indices for the front and rear of the queue
    int size;         // Current number of elements in the queue
} CircularQueue;

// Function to initialize a circular queue with a given capacity
CircularQueue* initializeQueue(int capacity) {
    CircularQueue* queue = (CircularQueue*)malloc(sizeof(CircularQueue));
    queue->capacity = capacity;
    queue->front = queue->rear = -1;  // Queue is empty initially
    queue->size = 0;

    // Allocate memory for the dynamic array
    queue->array = (int*)malloc(queue->capacity * sizeof(int));

    return queue;
}

// Function to check if the circular queue is empty
int isEmpty(CircularQueue* queue) {
    return queue->size == 0;
}

// Function to check if the circular queue is full
int isFull(CircularQueue* queue) {
    return queue->size == queue->capacity;
}

// Function to enqueue an element into the circular queue
void enqueue(CircularQueue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full! Cannot enqueue %d\n", item);
        return;
    }

    if (isEmpty(queue))
        queue->front = 0;  // Initialize front if the queue is empty

    // Increment rear in a circular fashion
    queue->rear = (queue->rear + 1) % queue->capacity;

    // Enqueue the element
    queue->array[queue->rear] = item;
    queue->size++;

    printf("%d enqueued to the queue\n", item);
}

// Function to dequeue an element from the circular queue
int dequeue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! Cannot dequeue\n");
        return -1;  // Return an error value
    }

    // Dequeue the element
    int item = queue->array[queue->front];

    // Increment front in a circular fashion
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;

    return item;
}

// Function to get the front element of the circular queue without removing it
int peek(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;  // Return an error value
    }

    return queue->array[queue->front];
}

// Function to free the memory allocated for the circular queue
void destroyQueue(CircularQueue* queue) {
    free(queue->array);
    free(queue);
}

// Example usage
int main() {
    int capacity = 5;
    CircularQueue* queue = initializeQueue(capacity);

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    printf("Front element: %d\n", peek(queue));

    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));

    printf("Is the queue empty? %s\n", isEmpty(queue) ? "Yes" : "No");

    destroyQueue(queue);

    return 0;
}
