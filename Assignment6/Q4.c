#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* prev;
    struct Node* next;
};
struct Node* head = NULL;
void insert(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void display() {
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int isPalindrome() {
    if (head == NULL) return 1;

    struct Node* left = head;
    struct Node* right = head;
    while (right->next != NULL) {
        right = right->next;
    }
    while (left != right && left->prev != right) {
        if (left->data != right->data)
            return 0;
        left = left->next;
        right = right->prev;
    }
    return 1;
}

int main() {
    insert('a');
    insert('b');
    insert('c');
    insert('b');
    insert('a');

    display();

    if (isPalindrome())
        printf("yes\n");
    else
        printf("no\n");

    return 0;
}
