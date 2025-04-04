#include <stdio.h>
#include <string.h>

typedef struct {
    char data[100];
    int top;
} StackType;

void init(StackType *s) { s->top = -1; }
void push(StackType *s, char c) { s->data[++(s->top)] = c; }
char pop(StackType *s) { return s->data[(s->top)--]; }

int check_matching(const char *str) {
    StackType s;
    init(&s);
    for (int i = 0; str[i]; i++) {
        char ch = str[i];
        if (ch == '(' || ch == '[' || ch == '{') push(&s, ch);
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (s.top == -1) return 0;
            char open = pop(&s);
            if ((open == '(' && ch != ')') ||
                (open == '[' && ch != ']') ||
                (open == '{' && ch != '}')) return 0;
        }
    }
    return s.top == -1;
}

int main() {
    char *p = "{ A[(i+1)] = 0; }";
    if (check_matching(p)) printf("성공\n");
    else printf("실패\n");
    return 0;
}
