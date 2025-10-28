# include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void start(int value){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr -> data = value;
    ptr -> next = head;
    head = ptr;
}

void traverse( struct Node *ptr){
      struct Node *ptr2 = head;
    while (ptr != NULL && ptr2 -> next != NULL){
        ptr = ptr ->next;
        ptr2 = ptr2 -> next -> next;
        printf(" The middle element is %d", ptr -> data);
    }
}
    int main(){
    start (10);
    start (20);
    start (30);
    traverse (head);
}

