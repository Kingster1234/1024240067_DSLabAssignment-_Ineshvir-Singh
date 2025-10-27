#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

int isFull() {
    return (front == (rear + 1) % SIZE);
}

int isEmpty() {
    return (front == -1);
}

void enqueue(int val) {
    if (isFull()) {
        printf("Queue is Full\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear = (rear + 1) % SIZE;
    queue[rear] = val;
    printf("Inserted %d\n", val);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }
    int val = queue[front];
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % SIZE;
    printf("Deleted element: %d\n", val);
}

void display() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }
    int i = front;
    printf("Queue elements: ");
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

void peek() {
    if (isEmpty())
        printf("Queue is Empty\n");
    else
        printf("Front element: %d\n", queue[front]);
}

int main() {
    int ch, val;
    while (1) {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Peek\n5.Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &ch) != 1) {
            while (getchar() != '\n');
            continue;
        }
        if (ch == 1) {
            printf("Enter value: ");
            scanf("%d", &val);
            enqueue(val);
        } else if (ch == 2)
            dequeue();
        else if (ch == 3)
            display();
        else if (ch == 4)
            peek();
        else if (ch == 5)
            break;
        else
            printf("Invalid choice\n");
    }
    return 0;
}
