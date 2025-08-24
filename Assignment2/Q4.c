#include <stdio.h>
#include <string.h>
#include <ctype.h>

// (a) Concatenate
void concatenate(char s1[], char s2[]) {
    strcat(s1, s2);
    printf("Concatenated: %s\n", s1);
}

// (b) Reverse
void reverse(char str[]) {
    int n = strlen(str);
    for (int i=0; i<n/2; i++) {
        char temp = str[i];
        str[i] = str[n-i-1];
        str[n-i-1] = temp;
    }
    printf("Reversed: %s\n", str);
}

// (c) Delete vowels
void deleteVowels(char str[]) {
    char res[100];
    int j=0;
    for (int i=0; str[i]; i++) {
        if (strchr("aeiouAEIOU", str[i]) == NULL) {
            res[j++] = str[i];
        }
    }
    res[j] = '\0';
    printf("Without vowels: %s\n", res);
}

// (d) Sort strings
void sortStrings(char arr[][50], int n) {
    char temp[50];
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if (strcmp(arr[i], arr[j]) > 0) {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
    printf("Sorted strings:\n");
    for (int i=0; i<n; i++) printf("%s\n", arr[i]);
}

// (e) Upper → Lower
void convertLower(char str[]) {
    for (int i=0; str[i]; i++)
        str[i] = tolower(str[i]);
    printf("Lowercase: %s\n", str);
}

int main() {
    char s1[100] = "Hello", s2[100] = "World";
    concatenate(s1, s2);

    char s3[100] = "ReverseMe";
    reverse(s3);

    char s4[100] = "RemoveVowels";
    deleteVowels(s4);

    char arr[3][50] = {"Banana", "Apple", "Mango"};
    sortStrings(arr, 3);

    char s5[100] = "HELLO";
    convertLower(s5);

    return 0;
}
