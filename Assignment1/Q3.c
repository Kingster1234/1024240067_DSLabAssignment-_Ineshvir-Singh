#include <stdio.h>

int main() {
    int i;
    int a[5] = {1};
    for(i = 0; i < 5; i++)
        printf("%d", a[i]);
    return 0;
}

/*
Output:
10000
Reason: First element is 1, rest are 0.
*/
