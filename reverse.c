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
    while (ptr!= NULL){
        printf("element is : %d\n", ptr -> data);
        ptr = ptr ->next;
    }
}

void reverse(){
    struct Node *prev =NULL;
    struct Node *current = head;
    struct Node *next = NULL;
    while (current!= NULL){
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
  head = prev;
}

int main(){
    start (10);
    start (20);
    start (30);
    traverse (head);
    reverse();
    traverse (head);
}

