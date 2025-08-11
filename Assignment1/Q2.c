#include <stdio.h>

int main() {
    int a[50], n, i, j, k;
    printf("Enter size: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(i = 0; i < n; i++) 
    scanf("%d", &a[i]);

    for(i = 0; i < n; i++) {
        for(j = i+1; j < n; j++) {
            if(a[i] == a[j]) {
                for(k = j; k < n-1; k++) {
                    a[k] = a[k+1];
                }
                n--;
                j--;
            }
        }
    }

    printf("Array after removing duplicates: ");
    for(i = 0; i < n; i++) 
    printf("%d ", a[i]);
    return 0;
}

/*
Logic:
1. Take the size of array and elements from user.
2. Use two loops:
   - Outer loop picks an element (a[i]).
   - Inner loop checks all elements after it.
3. If a duplicate is found (a[i] == a[j]):
   - Shift all elements after j one position to the left.
   - Decrease the size (n--) and adjust j to recheck.
4. Print the updated array which now has only unique elements.
*/
