#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>s
#define MAX_SIZE 5

// Structure to represent a Circular Queue
struct CircularQueue {
    int front, rear;
    int arr[MAX_SIZE];
};

// Function to initialize a Circular Queue
void initializeQueue(struct CircularQueue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the Circular Queue is empty
int isEmpty(struct CircularQueue *queue) {
    return (queue->front == -1 && queue->rear == -1);
}

// Function to check if the Circular Queue is full
int isFull(struct CircularQueue *queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

// Function to insert an element into the Circular Queue
void enqueue(struct CircularQueue *queue, int element) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    } else if (isEmpty(queue)) {
        // If the queue is empty, set both front and rear to 0
        queue->front = 0;
        queue->rear = 0;
    } else {
        // Move the rear to the next circular position
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }

    // Insert the element at the rear
    queue->arr[queue->rear] = element;

    printf("%d enqueued successfully.\n", element);
}

// Function to delete an element from the Circular Queue
void dequeue(struct CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    } else if (queue->front == queue->rear) {
        // If there is only one element in the queue, reset front and rear
        printf("%d dequeued successfully.\n", queue->arr[queue->front]);
        queue->front = -1;
        queue->rear = -1;
    } else {
        // Move the front to the next circular position
        printf("%d dequeued successfully.\n", queue->arr[queue->front]);
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
}

// Function to display the elements of the Circular Queue
void display(struct CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Elements in the Circular Queue: ");
    int i = queue->front;
    do {
        printf("%d ", queue->arr[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (queue->rear + 1) % MAX_SIZE);
    printf("\n");
}

int main() {
    struct CircularQueue queue;
    initializeQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    display(&queue);

    dequeue(&queue);
    display(&queue);

    enqueue(&queue, 40);
    enqueue(&queue, 50);
    display(&queue);

    enqueue(&queue, 60);
    enqueue(&queue, 70);
    return 0;
}
