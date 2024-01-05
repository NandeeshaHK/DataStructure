#include <stdio.h>
#include <stdlib.h>

// Structure to represent the stack
typedef struct {
    int* array;     // Dynamic array to store elements
    int capacity;   // Maximum capacity of the stack
    int top;        // Index of the top element
} Stack;

// Function to initialize a stack with a given capacity
Stack* initializeStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;  // Stack is empty initially

    // Allocate memory for the dynamic array
    stack->array = (int*)malloc(stack->capacity * sizeof(int));

    return stack;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Function to push an element onto the stack
void push(Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack overflow! Cannot push %d\n", item);
        return;
    }

    stack->array[++stack->top] = item;
    printf("%d pushed to the stack\n", item);
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop from an empty stack\n");
        return -1;  // Return an error value
    }

    return stack->array[stack->top--];
}

// Function to get the top element of the stack without removing it
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;  // Return an error value
    }

    return stack->array[stack->top];
}

// Function to free the memory allocated for the stack
void destroyStack(Stack* stack) {
    free(stack->array);
    free(stack);
}

// Example usage
int main() {
    int capacity = 5;
    Stack* stack = initializeStack(capacity);

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    printf("Top element: %d\n", peek(stack));

    printf("Popped element: %d\n", pop(stack));
    printf("Popped element: %d\n", pop(stack));

    printf("Is the stack empty? %s\n", isEmpty(stack) ? "Yes" : "No");

    destroyStack(stack);

    return 0;
}
