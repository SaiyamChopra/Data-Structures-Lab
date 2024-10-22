#include<stdio.h>
#include<ctype.h>

char stack[100];
int top = -1;

void push(char x) {
    top++;
    stack[top] = x;
}

char pop() {
    if (top == -1) {
        return -1;
    } else {
        char x = stack[top];
        top--;
        return x;
    }
}

int priority(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    if (x == '^') return 3;
    return 0;
}

int main() {
    char exp[100], x;
    printf("Enter the expression: ");
    scanf("%s", exp);

    char *e = exp;
    while (*e != '\0') {
        if (isalnum(*e)) {
            printf("%c ", *e);  // If operand, print it directly
        } else if (*e == '(') {
            push(*e);
        } else if (*e == ')') {
            while ((x = pop()) != '(') {
                printf("%c ", x);
            }
        } else {  // Operator
            while (top != -1 && priority(stack[top]) >= priority(*e)) {
                printf("%c ", pop());
            }
            push(*e);
        }
        e++;
    }

    // Pop remaining operators from the stack
    while (top != -1) {
        printf("%c ", pop());
    }

    return 0;
}
