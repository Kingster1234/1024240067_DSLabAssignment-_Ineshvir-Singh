#include <stdio.h>

void duplicateTwos(int arr[], int n) {
    int possible_dups = 0;
    int last = n - 1;

    for (int i = 0; i <= last - possible_dups; i++) {
        if (arr[i] == 2) {
            if (i == last - possible_dups) {
                arr[last] = 2;
                last--;
                break;
            }
            possible_dups++;
        }
    }

    int i = last - possible_dups;
    for (int j = last; i >= 0; i--, j--) {
        if (arr[i] == 2) {
            arr[j] = 2;
            j--;
            arr[j] = 2; 
        } else {
            arr[j] = arr[i];
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    duplicateTwos(arr, n);

    printf("Modified Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
