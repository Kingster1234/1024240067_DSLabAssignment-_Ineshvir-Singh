#include <stdio.h>

int main() {
    int A[] = {1, 2, 3, 4};
    int B[] = {3, 4, 5, 6};
    int n1 = 4, n2 = 4;

    int hash[1000] = {0};

    for(int i = 0; i < n1; i++)
        hash[A[i]] = 1;

    printf("Common Elements: ");
    for(int j = 0; j < n2; j++)
        if(hash[B[j]] == 1)
            printf("%d ", B[j]);

    printf("\n");
    return 0;
}
