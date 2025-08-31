#include <stdio.h>

void sort012(int arr[], int n) {
    int count0 = 0, count1 = 0, count2 = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 0)
            count0++;
        else if (arr[i] == 1)
            count1++;
        else
            count2++;
    }

    int index = 0;

    for (int i = 0; i < count0; i++)
        arr[index++] = 0;

    for (int i = 0; i < count1; i++)
        arr[index++] = 1;

    for (int i = 0; i < count2; i++)
        arr[index++] = 2;
}

int main() {
    int arr[] = {0, 2, 1, 2, 0, 1, 1, 0, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort012(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    return 0;
}
