#include <stdio.h>

int main() {
    int a[10][10], t[10][10], r, c, i, j;
    printf("Enter rows and cols: ");
    scanf("%d %d", &r, &c);

    printf("Enter matrix:\n");
    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            scanf("%d", &a[i][j]);

    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            t[j][i] = a[i][j];

    printf("Transpose:\n");
    for(i = 0; i < c; i++) {
        for(j = 0; j < r; j++)
            printf("%d ", t[i][j]);
        printf("\n");
    }
    return 0;
}

/*
Logic:
1. Read the matrix from user.
2. Swap rows with columns:
   - The element at position (i, j) in original goes to (j, i) in transpose.
3. Print the transposed matrix.
*/
