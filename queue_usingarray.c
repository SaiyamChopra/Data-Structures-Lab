#include <stdio.h>
#define MAX 5 // Maximum size of the queue

int queue[MAX];
int front = -1, rear = -1;

// Enqueue function to insert an element
void enqueue(int n) {
    if (rear == MAX - 1) { // Check if the queue is full
        printf("Queue is full\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = n;
        printf("Inserted %d\n", n);
    }
}

// Dequeue function to remove an element
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Element dequeued: %d\n", queue[front]);
        front++;
        if (front > rear) {
            // Reset the queue when empty
            front = -1;
            rear = -1;
        }
    }
}

// Display function to show the queue
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// Peek function to view the front element
void peek() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Front element is: %d\n", queue[front]);
    }
}

int main() {
    int choice, num;
    
    // User interaction loop
    while (1) {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Peek Front Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number to enqueue: ");
                scanf("%d", &num);
                enqueue(num);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                return 0; // Exit the program
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
