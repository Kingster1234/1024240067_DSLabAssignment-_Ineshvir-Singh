#include <stdio.h>
#include <string.h>

void generateBinary(int n) {
    char queue[1000][100];
    int front = 0, rear = 0;
    strcpy(queue[rear++], "1");
    for (int count = 1; count <= n; count++) {
        char current[100];
        strcpy(current, queue[front++]);
        printf("%s ", current);
        char temp[100];
        strcpy(temp, current);
        strcat(current, "0");
        strcat(temp, "1");
        strcpy(queue[rear++], current);
        strcpy(queue[rear++], temp);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    generateBinary(n);
    return 0;
}
