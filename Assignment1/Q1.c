#include <stdio.h>
#define MAX 100

int a[MAX];
int n = 0;

void create() {
    int i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

void display() {
    int i;
    if(n == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void insert() {
    int pos, val, i;
    printf("Enter position (0 to %d): ", n);
    scanf("%d", &pos);
    printf("Enter value: ");
    scanf("%d", &val);
    for(i = n; i > pos; i--) {
        a[i] = a[i-1];
    }
    a[pos] = val;
    n++;
}

void del() {
    int pos, i;
    printf("Enter position to delete (0 to %d): ", n-1);
    scanf("%d", &pos);
    for(i = pos; i < n-1; i++) {
        a[i] = a[i+1];
    }
    n--;
}

void search() {
    int key, i, f = 0;
    printf("Enter value to search: ");
    scanf("%d", &key);
    for(i = 0; i < n; i++) {
        if(a[i] == key) {
            printf("Found at index %d\n", i);
            f = 1;
        }
    }
    if(!f) printf("Not found.\n");
}

int main() {
    int ch;
    while(1) {
        printf("\nMENU:\n1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.SEARCH\n6.EXIT\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: del(); break;
            case 5: search(); break;
            case 6: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
