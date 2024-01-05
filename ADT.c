#include<stdio.h>
#include<stdlib.h>

// Define the structure for the stack node
struct Node {
    int data;
    struct Node* next;
};

// Define the stack ADT
struct Stack {
    struct Node* top;
};

// Function to initialize an empty stack
void initializeStack(struct Stack* stack) {
    stack->top = -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (stack->top == NULL) {
        // Stack is empty, handle error or return a special value
        return -1; // For simplicity, returning -1 for an empty stack
    }

    struct Node* temp = stack->top;
    int poppedValue = temp->data;
    stack->top = temp->next;
    free(temp);

    return poppedValue;
}

// Example usage
int main() {
    struct Stack myStack;
    initializeStack(&myStack);

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    printf("Popped element: %d\n", pop(&myStack));
    printf("Popped element: %d\n", pop(&myStack));
    printf("Popped element: %d\n", pop(&myStack));
    // printf("Popped element: %d\n", pop(&myStack));

    return 0;
}
