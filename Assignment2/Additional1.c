// time complexity n^2 (brute force)
#include <stdio.h>
#include <stdlib.h>

int countPairs(int arr[], int n, int k) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (abs(arr[i] - arr[j]) == k) {
                printf("Pair found: (%d, %d)\n", arr[i], arr[j]);
                count++;
            }
        }
    }
    return count;
}

int main() {
    int arr[] = {1, 5, 3, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    printf("Total pairs: %d\n", countPairs(arr, n, k));
    return 0;
}

// time complexity n logn (sorting)
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int countPairsTP(int arr[], int n, int k) {
    qsort(arr, n, sizeof(int), cmp);

    int i = 0, j = 1, count = 0;

    while (j < n) {
        int diff = arr[j] - arr[i];

        if (i == j) {
            j++;
            continue;
        }

        if (diff == k) {
            printf("Pair found: (%d, %d)\n", arr[i], arr[j]);
            count++;
            i++;
            j++;
        } else if (diff < k) {
            j++;
        } else {
            i++;
        }
    }
    return count;
}

int main() {
    int arr[] = {1, 5, 3, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    printf("Total pairs: %d\n", countPairsTP(arr, n, k));
    return 0;
}


