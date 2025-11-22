#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node* a = malloc(sizeof(struct Node));
    struct Node* b = malloc(sizeof(struct Node));
    struct Node* c = malloc(sizeof(struct Node));
    struct Node* d = malloc(sizeof(struct Node));

    a->data = 1; b->data = 2; c->data = 3; d->data = 4;

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = b;   

    struct Node* visited[100] = {0};  
    int idx = 0;

    struct Node* temp = a;

    while(temp) {
        for(int i = 0; i < idx; i++) {
            if(visited[i] == temp) {
                printf("true\n");
                return 0;
            }
        }
        visited[idx++] = temp;
        temp = temp->next;
    }

    printf("false\n");
    return 0;
}
