#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool canSplit(char s[]) {
    int n = strlen(s);
    for (int i = 1; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            char A[1005], B[1005], C[1005];

            strncpy(A, s, i);
            A[i] = '\0';

            strncpy(B, s + i, j - i);
            B[j - i] = '\0';

            strcpy(C, s + j);

            if (strlen(A) == 0 || strlen(B) == 0 || strlen(C) == 0) continue;

            if ((strstr(B, A) != NULL && strstr(C, A) != NULL) ||
                (strstr(A, B) != NULL && strstr(C, B) != NULL) ||
                (strstr(A, C) != NULL && strstr(B, C) != NULL)) {
                return true;
            }
        }
    }
    return false;
}
