#include <stdio.h>

int heap[100];
int size = 0;

void heapify(int i) {
    int largest = i, l = 2*i+1, r = 2*i+2, t;
    if (l < size && heap[l] > heap[largest]) largest = l;
    if (r < size && heap[r] > heap[largest]) largest = r;
    if (largest != i) {
        t = heap[i]; heap[i] = heap[largest]; heap[largest] = t;
        heapify(largest);
    }
}

void insertPQ(int v) {
    int i = size++;
    heap[i] = v;
    while (i && heap[(i-1)/2] < heap[i]) {
        int t = heap[i]; heap[i] = heap[(i-1)/2]; heap[(i-1)/2] = t;
        i = (i-1)/2;
    }
}

int deletePQ() {
    int root = heap[0];
    heap[0] = heap[--size];
    heapify(0);
    return root;
}

int main() {
    insertPQ(10);
    insertPQ(40);
    insertPQ(20);

    printf("%d ", deletePQ());
    printf("%d ", deletePQ());
}
