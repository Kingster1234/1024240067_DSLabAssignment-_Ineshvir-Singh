#include <stdio.h>

void improvedSelectionSort(int a[], int n) {
    int start = 0, end = n - 1;

    while (start < end) {
        int min = start, max = start;

        for (int i = start; i <= end; i++) {
            if (a[i] < a[min]) min = i;
            if (a[i] > a[max]) max = i;
        }

        int temp = a[start];
        a[start] = a[min];
        a[min] = temp;

        if (max == start)
            max = min;

        temp = a[end];
        a[end] = a[max];
        a[max] = temp;

        start++;
        end--;
    }
}

int main() {
    int a[] = {5, 2, 9, 1, 6, 3};
    int n = 6;

    improvedSelectionSort(a, n);

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}
