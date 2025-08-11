#include <stdio.h>

int main() {
    int a[50], n, i, t;
    printf("Enter size: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(i = 0; i < n; i++) 
    scanf("%d", &a[i]);

    for(i = 0; i < n/2; i++) {
        t = a[i];
        a[i] = a[n-i-1];
        a[n-i-1] = t;
    }

    printf("Reversed array: ");
    for(i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}

/*
Logic:
1. Read the array size and elements.
2. Swap the first element with the last, second with second last, and so on.
   - Only loop till n/2, because swapping happens in pairs.
3. Print the reversed array.
*/
