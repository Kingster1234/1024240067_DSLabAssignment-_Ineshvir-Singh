#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int hash[1000] = {0};

int checkDuplicates(struct Node* root) {
    if(root == NULL) return 0;

    if(hash[root->data] == 1)
        return 1;

    hash[root->data] = 1;

    return checkDuplicates(root->left) || checkDuplicates(root->right);
}

int main() {
    struct Node* root = malloc(sizeof(struct Node));
    struct Node* a = malloc(sizeof(struct Node));
    struct Node* b = malloc(sizeof(struct Node));

    root->data = 5;
    root->left = a;
    root->right = b;

    a->data = 3; 
    b->data = 5; 

    a->left = a->right = NULL;
    b->left = b->right = NULL;

    if(checkDuplicates(root))
        printf("Duplicates Found\n");
    else
        printf("No Duplicates\n");

    return 0;
}
