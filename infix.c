#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the given character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to get the precedence of an operator
int getPrecedence(char op) {
    if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0; // Lower precedence for other characters (operands)
}

// Function to convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
    // Initialize stack and output
    char stack[100], output[100];
    int top = -1, outIndex = 0;

    // Scan the infix expression
    for (int i = 0; i < strlen(infix); i++) {
        char token = infix[i];

        // Check for operands
        if ((token >= 'A' && token <= 'Z') || (token >= 'a' && token <= 'z')) {
            output[outIndex++] = token;
        } else if (isOperator(token)) { // Check for operators
            while (top >= 0 && getPrecedence(stack[top]) >= getPrecedence(token)) {
                output[outIndex++] = stack[top--];
            }
            stack[++top] = token;
        } else if (token == '(') { // Check for opening parenthesis
            stack[++top] = token;
        } else if (token == ')') { // Check for closing parenthesis
            while (top >= 0 && stack[top] != '(') {
                output[outIndex++] = stack[top--];
            }
            top--; // Discard the opening parenthesis
        }
    }

    // Pop any remaining operators from the stack
    while (top >= 0) {
        output[outIndex++] = stack[top--];
    }

    // Null-terminate the output string
    output[outIndex] = '\0';

    // Print the postfix expression
    printf("Postfix Expression: %s\n", output);
}

int main() {
    char infix[] = "A+B*C-D+E/R/(G+H)";
    char postfix[100];

    // Call the infix to postfix conversion function
    infixToPostfix(infix, postfix);

    return 0;
}
