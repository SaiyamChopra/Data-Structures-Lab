#include <stdio.h>
#include <ctype.h> // For isdigit()

#define MAX 20
int stack[MAX];
int top = -1;

// Function to push an element onto the stack
void push(int x) {
    if (top < MAX - 1) { // Check for stack overflow
        stack[++top] = x; // Increment top and push the element
    } else {
        printf("Stack overflow\n");
    }
}

// Function to pop an element from the stack
int pop() {
    if (top >= 0) { // Check for stack underflow
        return stack[top--]; // Return the top element and decrement top
    } else {
        printf("Stack underflow\n");
        return -1; // Return a sentinel value
    }
}

// Main function to evaluate postfix expression
int main() {
    char exp[30];
    int n1, n2, n3;

    printf("Enter the expression (postfix): ");
    scanf("%s", exp); // Read postfix expression

    for (int i = 0; exp[i] != '\0'; i++) { // Loop until end of the expression
        if (isdigit(exp[i])) { // If the character is a digit
            push(exp[i] - '0'); // Convert character to integer and push
        } else { // If the character is an operator
            n1 = pop(); // Pop top two elements
            n2 = pop();

            // Check for underflow
            if (n1 == -1 || n2 == -1) {
                printf("Error: Insufficient operands\n");
                return 1; // Exit with error
            }

            switch (exp[i]) { // Evaluate based on the operator
                case '+':
                    n3 = n2 + n1; // Note: n2 should be the first operand
                    break;
                case '-':
                    n3 = n2 - n1;
                    break;
                case '*':
                    n3 = n2 * n1;
                    break;
                case '/':
                    if (n1 != 0) {
                        n3 = n2 / n1;
                    } else {
                        printf("Error: Division by zero\n");
                        return 1; // Exit with error
                    }
                    break;
                default:
                    printf("Error: Invalid operator %c\n", exp[i]);
                    return 1; // Exit with error
            }
            push(n3); // Push the result back onto the stack
        }
    }

    // Final result
    if (top == 0) {
        printf("The result of the expression %s = %d\n", exp, pop()); // Output result
    } else {
        printf("Error: The expression is invalid\n");
    }

    return 0; // Return success
}
