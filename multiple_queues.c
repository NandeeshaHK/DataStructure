#include <stdio.h>
#include <stdlib.h>

// Structure to represent multiple queues
typedef struct {
    int* array;       // Dynamic array to store elements
    int capacity;     // Maximum capacity of each queue
    int numQueues;    // Number of queues
    int* fronts;       // Array to store the front index for each queue
    int* rears;        // Array to store the rear index for each queue
    int* sizes;        // Array to store the current size of each queue
} MultipleQueues;

// Function to initialize multiple queues with a given capacity and number of queues
MultipleQueues* initializeMultipleQueues(int capacity, int numQueues) {
    MultipleQueues* queues = (MultipleQueues*)malloc(sizeof(MultipleQueues));
    queues->capacity = capacity;
    queues->numQueues = numQueues;
    queues->fronts = (int*)malloc(numQueues * sizeof(int));
    queues->rears = (int*)malloc(numQueues * sizeof(int));
    queues->sizes = (int*)malloc(numQueues * sizeof(int));

    // Allocate memory for the dynamic array
    queues->array = (int*)malloc(capacity * numQueues * sizeof(int));

    // Initialize front, rear, and size for each queue
    for (int i = 0; i < numQueues; i++) {
        queues->fronts[i] = queues->rears[i] = -1;
        queues->sizes[i] = 0;
    }

    return queues;
}

// Function to check if a specific queue is empty
int isQueueEmpty(MultipleQueues* queues, int queueIndex) {
    return queues->sizes[queueIndex] == 0;
}

// Function to check if a specific queue is full
int isQueueFull(MultipleQueues* queues, int queueIndex) {
    return queues->sizes[queueIndex] == queues->capacity;
}

// Function to enqueue an element into a specific queue
void enqueueToQueue(MultipleQueues* queues, int queueIndex, int item) {
    if (isQueueFull(queues, queueIndex)) {
        printf("Queue %d is full! Cannot enqueue %d\n", queueIndex, item);
        return;
    }

    // Calculate the index for the given queue
    int index = queueIndex * queues->capacity + (queues->rears[queueIndex] + 1) % queues->capacity;

    queues->array[index] = item;
    queues->rears[queueIndex] = (queues->rears[queueIndex] + 1) % queues->capacity;
    queues->sizes[queueIndex]++;

    printf("%d enqueued to Queue %d\n", item, queueIndex);
}

// Function to dequeue an element from a specific queue
int dequeueFromQueue(MultipleQueues* queues, int queueIndex) {
    if (isQueueEmpty(queues, queueIndex)) {
        printf("Queue %d is empty! Cannot dequeue\n", queueIndex);
        return -1;  // Return an error value
    }

    // Calculate the index for the given queue
    int index = queueIndex * queues->capacity + queues->fronts[queueIndex];
    int item = queues->array[index];

    queues->fronts[queueIndex] = (queues->fronts[queueIndex] + 1) % queues->capacity;
    queues->sizes[queueIndex]--;

    return item;
}

// Function to free the memory allocated for multiple queues
void destroyMultipleQueues(MultipleQueues* queues) {
    free(queues->array);
    free(queues->fronts);
    free(queues->rears);
    free(queues->sizes);
    free(queues);
}

// Example usage
int main() {
    int capacity = 3;
    int numQueues = 2;
    MultipleQueues* queues = initializeMultipleQueues(capacity, numQueues);

    enqueueToQueue(queues, 0, 1);
    enqueueToQueue(queues, 1, 2);
    enqueueToQueue(queues, 0, 3);

    printf("Dequeued element from Queue 1: %d\n", dequeueFromQueue(queues, 1));
    printf("Dequeued element from Queue 0: %d\n", dequeueFromQueue(queues, 0));

    destroyMultipleQueues(queues);

    return 0;
}
