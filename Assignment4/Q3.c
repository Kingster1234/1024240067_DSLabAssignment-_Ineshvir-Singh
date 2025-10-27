#include <stdio.h>
#define SIZE 100

int main() {
    int arr[SIZE], n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int mid = n / 2;
    printf("Output: ");
    for (int i = 0; i < mid; i++)
        printf("%d %d ", arr[i], arr[mid + i]);
    printf("\n");
    return 0;
}
