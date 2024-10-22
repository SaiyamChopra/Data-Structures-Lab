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

// Function to enqueue (insert at the end of the queue)
struct Node* enqueue(struct Node* rear, int data) {
    struct Node* newNode = createNode(data);
    if (rear == NULL) {
        return newNode;
    }
    rear->next = newNode;
    return newNode;
}

// Function to dequeue (remove from the front of the queue)
// Returns the new front of the queue
struct Node* dequeue(struct Node* front, int* dequeuedData) {
    if (front == NULL) {
        printf("Queue underflow. No elements to dequeue.\n");
        return NULL;
    }
    struct Node* temp = front;
    *dequeuedData = temp->data;   // Save the dequeued data
    front = front->next;          // Move front to the next node
    free(temp);                   // Free the old front node
    return front;                 // Return the new front pointer
}

// Function to display the queue
void displayQueue(struct Node* front) {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* front = NULL;
    struct Node* rear = NULL;
    int choice, value, dequeuedData;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Enqueue operation
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                if (rear == NULL) {
                    front = rear = enqueue(rear, value); // First element, update both front and rear
                } else {
                    rear = enqueue(rear, value); // Subsequent elements, update rear only
                }
                printf("%d enqueued successfully.\n", value);
                break;

            case 2:
                // Dequeue operation
                if (front == NULL) {
                    printf("Queue is empty. Cannot dequeue.\n");
                } else {
                    front = dequeue(front, &dequeuedData); // Update front pointer after dequeuing
                    if (front == NULL) {
                        rear = NULL; // If the queue is empty after dequeuing, set rear to NULL
                    }
                    printf("Dequeued value: %d\n", dequeuedData);
                }
                break;

            case 3:
                // Display the queue
                displayQueue(front);
                break;

            case 4:
                // Exit the program
                printf("Exiting the program.\n");
                exit(0);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

