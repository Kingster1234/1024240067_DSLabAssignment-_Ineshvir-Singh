#include <stdio.h>
#define MAX 100

typedef struct {
    int row, col, val;
} Term;

// Transpose
void transpose(Term a[], Term b[]) {
    int n = a[0].val;
    b[0].row = a[0].col; b[0].col = a[0].row; b[0].val = n;
    int q=1;
    for (int c=0; c<a[0].col; c++) {
        for (int i=1; i<=n; i++) {
            if (a[i].col == c) {
                b[q].row = a[i].col;
                b[q].col = a[i].row;
                b[q].val = a[i].val;
                q++;
            }
        }
    }
}

// Addition and multiplication 
int main() {
    Term a[MAX] = {{3,3,3}, {0,0,5}, {1,1,8}, {2,2,9}};
    Term b[MAX];
    transpose(a, b);

    printf("Transpose triplet:\n");
    for (int i=0; i<=b[0].val; i++)
        printf("%d %d %d\n", b[i].row, b[i].col, b[i].val);
    return 0;
}
