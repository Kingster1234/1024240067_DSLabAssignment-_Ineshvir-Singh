#include <stdio.h>

int binarySearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; 
}

int main() {
    int arr[] = {2, 4, 6, 10, 14, 18, 22};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 10;
    int result = binarySearch(arr, n, x);
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");
    return 0;
}
