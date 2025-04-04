#include <stdio.h>
#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} StackType;

void init(StackType *s) { s->top = -1; }
void push(StackType *s, int item) { s->data[++(s->top)] = item; }
int pop(StackType *s) { return s->data[(s->top)--]; }

int main() {
    StackType s;
    init(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    return 0;
}
