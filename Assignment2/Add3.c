#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool areAnagrams(char str1[], char str2[]) {
    int n1 = strlen(str1);
    int n2 = strlen(str2);

    if (n1 != n2) return false;

    int freq[26] = {0};

    for (int i = 0; i < n1; i++) {
        freq[str1[i] - 'a']++;  
        freq[str2[i] - 'a']--;   
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0) return false;
    }

    return true;
}

int main() {
    int t;
    scanf("%d", &t);  

    while (t--) {
        char str1[1005], str2[1005];
        scanf("%s %s", str1, str2);

        if (areAnagrams(str1, str2))
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
