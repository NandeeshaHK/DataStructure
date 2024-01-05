#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue {
    int items[MAX_SIZE];
    int front, rear;
};

// Function to initialize the queue
void initializeQueue(struct Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *queue) {
    return queue->front == -1;
}

// Function to check if the queue is full
int isFull(struct Queue *queue) {
    return (queue->front == 0 && queue->rear == MAX_SIZE - 1) || (queue->front == queue->rear + 1);
}

// Function to enqueue (insert) an element into the queue
void enqueue(struct Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue overflow!\n");
        return;
    }

    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else if (queue->rear == MAX_SIZE - 1) {
        queue->rear = 0;
    } else {
        queue->rear++;
    }

    queue->items[queue->rear] = value;
}

// Function to dequeue (remove) an element from the queue
int dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow!\n");
        return -1;
    }

    int value = queue->items[queue->front];

    if (queue->front == queue->rear) {
        // Only one element in the queue
        initializeQueue(queue);
    } else if (queue->front == MAX_SIZE - 1) {
        queue->front = 0;
    } else {
        queue->front++;
    }

    return value;
}

int main() {
    struct Queue myQueue;
    initializeQueue(&myQueue);

    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);

    printf("Dequeued from queue: %d\n", dequeue(&myQueue));
    printf("Dequeued from queue: %d\n", dequeue(&myQueue));

    return 0;
}
