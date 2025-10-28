#include <stdio.h>
#include <stdlib.h>

struct Node *head = NULL;

struct Node {
    int data;
    struct Node *next;
} s;

void start(int value){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr -> data = value;
    ptr -> next = head;
    head = ptr;
}

void between(struct Node *p, int value){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
     ptr -> data = value;
     ptr -> next = p -> next;
     p-> next = ptr ;
}

void end(int value){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));   
    ptr -> data = value;
    ptr -> next = NULL;
      if (head == NULL) {
        head = ptr;
        return;
    }
    struct Node *p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = ptr;
}

void Traversal(struct Node *ptr){
    while (ptr != NULL){
        printf("Element : %d\n", ptr ->data);
        ptr = ptr -> next;
        
    }
}

int main() {
    start(10);
    start(20);
    start(30);

    between(head -> next, 25);
    end (5);
    Traversal(head);

    return 0;
}