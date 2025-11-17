#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
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

struct Node* minValueNode(struct Node* node) {
    while (node->left)
        node = node->left;
    return node;
}

struct Node* delete(struct Node* root, int key) {
    if (!root) return root;

    if (key < root->data)
        root->left = delete(root->left, key);
    else if (key > root->data)
        root->right = delete(root->right, key);
    else {
        if (!root->left) return root->right;
        if (!root->right) return root->left;

        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

int maxDepth(struct Node* root) {
    if (!root) return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return (l > r ? l : r) + 1;
}

int minDepth(struct Node* root) {
    if (!root) return 0;
    int l = minDepth(root->left);
    int r = minDepth(root->right);
    if (!root->left || !root->right)
        return 1 + (l > r ? l : r);
    return 1 + (l < r ? l : r);
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 5);
    insert(root, 40);

    root = delete(root, 10);

    printf("Max Depth: %d\n", maxDepth(root));
    printf("Min Depth: %d\n", minDepth(root));
}
