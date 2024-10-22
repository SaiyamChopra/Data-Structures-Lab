#include <stdio.h>
#define max 5  // Define the maximum size of the queue

int queue[max];
int front = -1, rear = -1;

void enqueue(int n) {
    if ((rear + 1) % max == front) {
        printf("Queue is full\n");
    } else {
        if (front == -1) {
            front = 0;  // Initialize front when the first element is added
        }
        rear = (rear + 1) % max;
        queue[rear] = n;
        printf("Inserted %d\n", n);
    }
}

void dequeue() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Element dequeued: %d\n", queue[front]);
        if (front == rear) {
            // Queue becomes empty
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % max;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are: ");
        int i = front;
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % max;
        }
        printf("%d\n", queue[rear]);  // Print the last element
    }
}

void peek() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Front element is: %d\n", queue[front]);
    }
}

int main() {
    int choice, value;
    
    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
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
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
