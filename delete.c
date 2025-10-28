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
void delete(){
    struct Node *ptr =head;
    head = head -> next;
    free (ptr);
}

int main(){
    start (10);
    start (20);
    start (30);
    traverse(head);
    delete();
    traverse(head);
}
