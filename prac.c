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




int main()
{
    char exp[20];
    int n1,n2,n3;
printf("ENter the exp");
scanf("%s",exp);
for(int i=0;exp[i]!='\0';i++)
{
    if(isdigit(exp[i]))
    {
        push(exp[i]-'0');

    }
    else
    {
        n1=pop();
        n2=pop();

    
 switch(exp[i])
 {
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
  push(n3);
    }



}
 printf("the final exp is %d",pop());
}