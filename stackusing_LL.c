#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element onto the stack
struct Node* push(struct Node* top, int data) {
struct Node* newnode=createNode(data);
newnode->next=top;
return newnode;
}

// Function to pop an element from the stack
struct Node* pop(struct Node* top, int* poppedData) {
    if (top == NULL) {
        printf("Stack underflow\n");
        return NULL;
    }
    struct Node* temp=top;
      *poppedData = temp->data;
    top=top->next;
    free(temp);
    return top;
}

// Function to display the stack
void displayStack(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* top = NULL; // Initialize the stack
    int choice, value, poppedValue;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                top = push(top, value);
                break;
            case 2:
                top = pop(top, &poppedValue);
                if (top != NULL) {
                    printf("Popped value: %d\n", poppedValue);
                }
                break;
            case 3:
                displayStack(top);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
