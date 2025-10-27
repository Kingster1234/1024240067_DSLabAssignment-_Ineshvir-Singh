#include <stdio.h>
#define MAX 5  

int queue[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return (front == -1 || front > rear);
}

int isFull() {
    return (rear == MAX - 1);
}

void enqueue(int value) {
    if (isFull()) {
        printf("\nQueue full.... Cannot insert %d\n", value);
        return;
    }
    if (front == -1)  
        front = 0;
    rear++;
    queue[rear] = value;
    printf("\nInserted %d into the queue.\n", value);
}

void dequeue() {
    if (isEmpty()) {
        printf("\nQueue empty..... No elements to delete.\n");
        return;
    }
    printf("\nDeleted element: %d\n", queue[front]);
    front++;
}

void peek() {
    if (isEmpty()) {
        printf("\nQueue is empty. Nothing to peek.\n");
        return;
    }
    printf("\nFront element is: %d\n", queue[front]);
}

void display() {
    if (isEmpty()) {
        printf("\nQueue is empty.\n");
        return;
    }
    printf("\nQueue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Check if Empty\n");
        printf("6. Check if Full\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
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
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            if (isEmpty()) printf("\nQueue is Empty.\n");
            else printf("\nQueue is NOT Empty.\n");
            break;
        case 6:
            if (isFull()) printf("\nQueue is Full.\n");
            else printf("\nQueue is NOT Full.\n");
            break;
        case 0:
            printf("\nExiting...\n");
            return 0;
        default:
            printf("\nInvalid choice! Try again.\n");
        }
    }
}
