#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the given character is an operand
int isOperand(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

// Function to convert postfix to infix
void postfixToInfix(char postfix[], char infix[]) {
    // Initialize stack
    char stack[100][100];
    int top = -1;

    // Scan the postfix expression
    for (int i = 0; i < strlen(postfix); i++) {
        char token = postfix[i];

        if (isOperand(token)) {
            // If the token is an operand, push it onto the stack
            stack[++top][0] = token;
            stack[top][1] = '\0'; // Null-terminate the string
        } else {
            // If the token is an operator, pop operands, apply the operator, and push the result
            char operand2[100], operand1[100];
            strcpy(operand2, stack[top--]);
            strcpy(operand1, stack[top--]);

            // Combine operands with the operator
            sprintf(stack[++top], "(%s%c%s)", operand1, token, operand2);
        }
    }

    // The final infix expression is in the stack
    strcpy(infix, stack[top]);

    // Print the infix expression
    printf("Infix Expression: %s\n", infix);
}

int main() {
    char postfix[] = "ABC*+D-ER/GH+/+";
    char infix[100];

    // Call the postfix to infix conversion function
    postfixToInfix(postfix, infix);

    return 0;
}
