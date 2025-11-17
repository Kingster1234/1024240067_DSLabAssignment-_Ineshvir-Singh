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

void inorderDLL(struct Node* root, struct Node** head, struct Node** prev) {
    if (!root) return;

    inorderDLL(root->left, head, prev);

    if (!(*head)) *head = root;
    else {
        (*prev)->right = root;
        root->left = *prev;
    }
    *prev = root;

    inorderDLL(root->right, head, prev);
}

int main() {
    struct Node *T1 = newNode(20);
    T1->left = newNode(10);
    T1->right = newNode(30);

    struct Node *T2 = newNode(25);
    T2->left = newNode(5);
    T2->right = newNode(70);

    struct Node *head = NULL, *prev = NULL;

    inorderDLL(T1, &head, &prev);
    inorderDLL(T2, &head, &prev);

    prev->right = NULL;

    struct Node* curr = head;
    while (curr) {
        printf("%d <-> ", curr->data);
        curr = curr->right;
    }
    printf("NULL");
}
