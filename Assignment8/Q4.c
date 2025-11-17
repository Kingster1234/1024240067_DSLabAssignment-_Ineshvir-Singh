#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int d) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = d;
    n->left = n->right = NULL;
    return n;
}

int isBSTUtil(struct Node* root, int min, int max) {
    if (!root) return 1;
    if (root->data < min || root->data > max) return 0;
    return isBSTUtil(root->left, min, root->data - 1) &&
           isBSTUtil(root->right, root->data + 1, max);
}

int isBST(struct Node* root) {
    return isBSTUtil(root, -100000, 100000);
}

int main() {
    struct Node* root = newNode(20);
    root->left = newNode(10);
    root->right = newNode(30);

    printf("%s\n", isBST(root) ? "BST" : "Not BST");
}
