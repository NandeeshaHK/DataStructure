#include <stdio.h>
#include <stdlib.h>

// Function to perform basic arithmetic operations
int performOperation(char operator, int operand1, int operand2) {
    switch (operator) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
        default:
            // Handle unexpected operators (not needed for a valid postfix expression)
            return 0;
    }
}

// Function to evaluate postfix expression
int evaluatePostfix(char* postfix) {
    int stack[100]; // Assuming the maximum number of operands is 100
    int top = -1;   // Initialize top of the stack

    // Loop through each character in the postfix expression
    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            // If the character is a digit, push it onto the stack
            stack[++top] = postfix[i] - '0'; // Convert char to int
        } else {
            // If the character is an operator, pop two operands, perform operation, and push result
            int operand2 = stack[top--];
            int operand1 = stack[top--];
            int result = performOperation(postfix[i], operand1, operand2);
            stack[++top] = result; // Push result onto the stack
        }
    }

    // The final result will be at the top of the stack
    return stack[top];
}

int main() {
    char postfixExpression[] = "723+-382/*-";
    int result = evaluatePostfix(postfixExpression);

    printf("Result of the postfix expression: %d\n", result);

    return 0;
}
