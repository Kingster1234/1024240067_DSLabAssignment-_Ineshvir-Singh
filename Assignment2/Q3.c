#include <stdio.h>

int findMissing(int arr[], int n) {
    int low = 0, high = n - 1, mid;
    
    while (low <= high) {
        mid = (low + high) / 2;
        
        if (arr[mid] - arr[0] != mid) {
            high = mid - 1; 
        } else {
            low = mid + 1; 
        }
    }
    return arr[0] + low;
}

int main() {
    int arr[] = {1, 2, 3, 4, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Missing number is: %d\n", findMissing(arr, n));
    return 0;
}