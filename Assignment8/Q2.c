#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

struct Node* insert(struct Node* root, int key) {
    if (!root) return newNode(key);
    if (key < root->data) root->left = insert(root->left, key);
    else if (key > root->data) root->right = insert(root->right, key);
    return root;
}

struct Node* searchRec(struct Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return searchRec(root->left, key);
    return searchRec(root->right, key);
}

struct Node* searchNonRec(struct Node* root, int key) {
    while (root) {
        if (key == root->data) return root;
        root = (key < root->data) ? root->left : root->right;
    }
    return NULL;
}

int maxBST(struct Node* root) {
    while (root->right)
        root = root->right;
    return root->data;
}

int minBST(struct Node* root) {
    while (root->left)
        root = root->left;
    return root->data;
}

struct Node* inorderSuccessor(struct Node* root, struct Node* x) {
    struct Node* succ = NULL;
    while (root) {
        if (x->data < root->data) {
            succ = root;
            root = root->left;
        } else root = root->right;
    }
    return succ;
}

struct Node* inorderPredecessor(struct Node* root, struct Node* x) {
    struct Node* pred = NULL;
    while (root) {
        if (x->data > root->data) {
            pred = root;
            root = root->right;
        } else root = root->left;
    }
    return pred;
}


int main() {
    struct Node* root = NULL;
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 5);

    struct Node* r1 = searchRec(root, 10);
    struct Node* r2 = searchNonRec(root, 30);

    printf("Recursive Search: %s\n", (r1 ? "Found" : "Not Found"));
    printf("Non-Recursive Search: %s\n", (r2 ? "Found" : "Not Found"));
}
