#include <stdio.h>

void selectionSort(int a[], int n) {
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;

        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

int main() {
    int a[] = {64, 25, 12, 22, 11};
    int n = 5;
    selectionSort(a, n);

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}
