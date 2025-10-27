#include <stdio.h>
#define SIZE 100

int queue[SIZE];
int front = -1, rear = -1;

int isEmpty() {
    return front == -1;
}

void enqueue(int val) {
    if (rear == SIZE - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = val;
}

int dequeue() {
    if (isEmpty()) return -1;
    int val = queue[front];
    if (front == rear)
        front = rear = -1;
    else
        front++;
    return val;
}

int size() {
    if (isEmpty()) return 0;
    return rear - front + 1;
}

int minIndex(int n) {
    int min_index = -1, min_val = 1e9;
    for (int i = 0; i < n; i++) {
        int curr = dequeue();
        if (curr <= min_val && min_index == -1) {
            min_index = i;
            min_val = curr;
        } else if (curr < min_val) {
            min_val = curr;
            min_index = i;
        }
        enqueue(curr);
    }
    return min_index;
}

void insertMinToRear(int min_index, int n) {
    int min_val;
    for (int i = 0; i < n; i++) {
        int curr = dequeue();
        if (i == min_index)
            min_val = curr;
        else
            enqueue(curr);
    }
    enqueue(min_val);
}

void sortQueue() {
    int n = size();
    for (int i = 1; i <= n; i++) {
        int min_index = -1, min_val = 1e9;
        int len = n - i + 1;
        for (int j = 0; j < len; j++) {
            int curr = dequeue();
            if (curr <= min_val && min_index == -1) {
                min_val = curr;
                min_index = j;
            } else if (curr < min_val) {
                min_val = curr;
                min_index = j;
            }
            enqueue(curr);
        }
        for (int j = 0; j < len; j++) {
            int curr = dequeue();
            if (j != min_index)
                enqueue(curr);
            else
                min_val = curr;
        }
        enqueue(min_val);
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    int n, val;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(val);
    }
    printf("Original Queue: ");
    display();
    sortQueue();
    printf("Sorted Queue: ");
    display();
    return 0;
}
