#include <stdio.h>
#define SIZE 100

int q1[SIZE], q2[SIZE];
int f1 = -1, r1 = -1, f2 = -1, r2 = -1;

int isEmpty1() { return f1 == -1; }
int isEmpty2() { return f2 == -1; }

void enqueue1(int x) {
    if (r1 == SIZE - 1) return;
    if (f1 == -1) f1 = 0;
    q1[++r1] = x;
}

void enqueue2(int x) {
    if (r2 == SIZE - 1) return;
    if (f2 == -1) f2 = 0;
    q2[++r2] = x;
}

int dequeue1() {
    if (isEmpty1()) return -1;
    int x = q1[f1];
    if (f1 == r1) f1 = r1 = -1;
    else f1++;
    return x;
}

int dequeue2() {
    if (isEmpty2()) return -1;
    int x = q2[f2];
    if (f2 == r2) f2 = r2 = -1;
    else f2++;
    return x;
}

void push(int x) {
    enqueue2(x);
    while (!isEmpty1()) enqueue2(dequeue1());
    int *t1 = q1, *t2 = q2;
    int tf1 = f1, tr1 = r1, tf2 = f2, tr2 = r2;
    for (int i = 0; i < SIZE; i++) {
        int temp = q1[i];
        q1[i] = q2[i];
        q2[i] = temp;
    }
    f1 = tf2; r1 = tr2; f2 = tf1; r2 = tr1;
}

void pop() {
    if (isEmpty1()) printf("Stack Empty\n");
    else printf("Popped: %d\n", dequeue1());
}

void display() {
    if (isEmpty1()) printf("Stack Empty\n");
    else {
        printf("Stack: ");
        for (int i = f1; i <= r1; i++) printf("%d ", q1[i]);
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
