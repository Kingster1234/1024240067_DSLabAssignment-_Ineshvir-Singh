#include <stdio.h>
#define SIZE 100

int q[SIZE];
int front = -1, rear = -1;

int isEmpty() { return front == -1; }

void enqueue(int x) {
    if (rear == SIZE - 1) return;
    if (front == -1) front = 0;
    q[++rear] = x;
}

int dequeue() {
    if (isEmpty()) return -1;
    int x = q[front];
    if (front == rear) front = rear = -1;
    else front++;
    return x;
}

void push(int x) {
    enqueue(x);
    for (int i = 0; i < rear - front; i++)
        enqueue(dequeue());
}

void pop() {
    if (isEmpty()) printf("Stack Empty\n");
    else printf("Popped: %d\n", dequeue());
}

void display() {
    if (isEmpty()) printf("Stack Empty\n");
    else {
        printf("Stack: ");
        for (int i = front; i <= rear; i++) printf("%d ", q[i]);
        printf("\n");
    }
}

int main() {
    int ch, val;
    while (1) {
        printf("\n1.Push 2.Pop 3.Display 4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        if (ch == 1) {
            printf("Enter value: ");
            scanf("%d", &val);
            push(val);
        } else if (ch == 2)
            pop();
        else if (ch == 3)
            display();
        else if (ch == 4)
            break;
    }
    return 0;
}
