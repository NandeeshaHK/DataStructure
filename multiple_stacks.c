#include <stdio.h>
#include <stdlib.h>

// Structure to represent multiple stacks
typedef struct {
    int* array;       // Dynamic array to store elements
    int capacity;     // Maximum capacity of each stack
    int numStacks;    // Number of stacks
    int* tops;         // Array to store the top index for each stack
} MultipleStacks;

// Function to initialize multiple stacks with a given capacity and number of stacks
MultipleStacks* initializeMultipleStacks(int capacity, int numStacks) {
    MultipleStacks* stacks = (MultipleStacks*)malloc(sizeof(MultipleStacks));
    stacks->capacity = capacity;
    stacks->numStacks = numStacks;
    stacks->tops = (int*)malloc(numStacks * sizeof(int));

    // Allocate memory for the dynamic array
    stacks->array = (int*)malloc(capacity * numStacks * sizeof(int));

    // Initialize top indices for each stack
    for (int i = 0; i < numStacks; i++)
        stacks->tops[i] = -1;

    return stacks;
}

// Function to check if a specific stack is empty
int isStackEmpty(MultipleStacks* stacks, int stackIndex) {
    return stacks->tops[stackIndex] == -1;
}

// Function to check if a specific stack is full
int isStackFull(MultipleStacks* stacks, int stackIndex) {
    return stacks->tops[stackIndex] == stacks->capacity - 1;
}

// Function to push an element onto a specific stack
void pushToStack(MultipleStacks* stacks, int stackIndex, int item) {
    if (isStackFull(stacks, stackIndex)) {
        printf("Stack %d is full! Cannot push %d\n", stackIndex, item);
        return;
    }

    // Calculate the index for the given stack
    int index = stackIndex * stacks->capacity + stacks->tops[stackIndex] + 1;

    stacks->array[index] = item;
    stacks->tops[stackIndex]++;

    printf("%d pushed to Stack %d\n", item, stackIndex);
}

// Function to pop an element from a specific stack
int popFromStack(MultipleStacks* stacks, int stackIndex) {
    if (isStackEmpty(stacks, stackIndex)) {
        printf("Stack %d is empty! Cannot pop\n", stackIndex);
        return -1;  // Return an error value
    }

    // Calculate the index for the given stack
    int index = stackIndex * stacks->capacity + stacks->tops[stackIndex];
    int item = stacks->array[index];

    stacks->tops[stackIndex]--;

    return item;
}

// Function to free the memory allocated for multiple stacks
void destroyMultipleStacks(MultipleStacks* stacks) {
    free(stacks->array);
    free(stacks->tops);
    free(stacks);
}

// Example usage
int main() {
    int capacity = 3;
    int numStacks = 2;
    MultipleStacks* stacks = initializeMultipleStacks(capacity, numStacks);

    pushToStack(stacks, 0, 1);
    pushToStack(stacks, 1, 2);
    pushToStack(stacks, 0, 3);

    printf("Popped element from Stack 1: %d\n", popFromStack(stacks, 1));
    printf("Popped element from Stack 0: %d\n", popFromStack(stacks, 0));

    destroyMultipleStacks(stacks);

    return 0;
}
