#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char arr[1000];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

void push(Stack *s, char c) {
    s->arr[++(s->top)] = c;
}

char pop(Stack *s) {
    if (s->top == -1) return '\0';
    return s->arr[(s->top)--];
}

char peek(Stack *s) {
    if (s->top == -1) return '\0';
    return s->arr[s->top];
}

int Matching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

int Balanced(char *expr) {
    Stack s;
    init(&s);

    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];

   
        if (c == '(' || c == '[' || c == '{') {
            push(&s, c);
        }
       
        else if (c == ')' || c == ']' || c == '}') {
            if (s.top == -1) return 0;  
            char open = pop(&s);
            if (!Matching(open, c)) return 0;  
        }
    }

    return (s.top == -1);  
}

int main() {
    char expr[1000];
    printf("Enter expression: ");
    scanf("%s", expr);

    if (Balanced(expr))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}
