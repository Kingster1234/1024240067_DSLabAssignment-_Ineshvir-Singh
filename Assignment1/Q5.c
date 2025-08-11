#include <stdio.h>

int main() {
    int a[10][10], r, c, i, j, sum;
    printf("Enter rows and cols: ");
    scanf("%d %d", &r, &c);

    printf("Enter matrix:\n");
    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            scanf("%d", &a[i][j]);

    for(i = 0; i < r; i++) {
        sum = 0;
        for(j = 0; j < c; j++)
            sum += a[i][j];
        printf("Sum of row %d = %d\n", i, sum);
    }

    for(j = 0; j < c; j++) {
        sum = 0;
        for(i = 0; i < r; i++)
            sum += a[i][j];
        printf("Sum of col %d = %d\n", j, sum);
    }
    return 0;
}
