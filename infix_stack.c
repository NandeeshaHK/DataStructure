#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Define a stack structure
typedef struct {
    char* array;
    int top;
    unsigned capacity;
} Stack;

// Function to initialize the stack
Stack* createStack(unsigned capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(Stack* stack) {
    return (stack->top == stack->capacity -1);
}

// Function to push an element to the stack
void push(Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
char pop(Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$'; // Special character to indicate an empty stack
}

// Function to get the precedence of an operator
int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Function to convert Infix expression to Postfix expression
void infixToPostfix(char* infixExpression) {
    Stack* stack = createStack(strlen(infixExpression));
    int i, j;

    for (i = 0, j = -1; infixExpression[i]; ++i) {
        // If the scanned character is an operand, add it to the output
        if (isalnum(infixExpression[i]))
            infixExpression[++j] = infixExpression[i];
        // If the scanned character is an operator
        else if (infixExpression[i] == '(')
            push(stack, infixExpression[i]);
        else if (infixExpression[i] == ')') {
            while (!isEmpty(stack) && stack->array[stack->top] != '(')
                infixExpression[++j] = pop(stack);
            if (!isEmpty(stack) && stack->array[stack->top] != '(')
                return; // Invalid expression
            else
                pop(stack);
        } else {
            while (!isEmpty(stack) && getPrecedence(infixExpression[i]) <= getPrecedence(stack->array[stack->top]))
                infixExpression[++j] = pop(stack);
            push(stack, infixExpression[i]);
        }
    }

    // Pop all the operators from the stack
    while (!isEmpty(stack))
        infixExpression[++j] = pop(stack);

    // Null-terminate the postfix expression
    infixExpression[++j] = '\0';
}

// Example usage
int main() {
    char infixExpression[100];

    printf("Enter an Infix expression: ");
    scanf("%s", infixExpression);

    infixToPostfix(infixExpression);

    printf("Postfix expression: %s\n", infixExpression);

    return 0;
}
