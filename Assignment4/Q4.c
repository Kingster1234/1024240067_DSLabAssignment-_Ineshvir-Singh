#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int freq[256] = {0};
    char q[100];
    int front = 0, rear = -1;
    printf("Enter string: ");
    scanf("%s", str);
    for (int i = 0; i < strlen(str); i++) {
        freq[str[i]]++;
        q[++rear] = str[i];
        while (front <= rear && freq[q[front]] > 1)
            front++;
        if (front > rear)
            printf("-1 ");
        else
            printf("%c ", q[front]);
    }
    printf("\n");
    return 0;
}
