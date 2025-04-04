
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

// === 스택 코드 시작 ===
typedef char element;

typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

void init_stack(StackType *s) {
    s->top = -1;
}

int is_empty(StackType *s) {
    return (s->top == -1);
}

int is_full(StackType *s) {
    return (s->top == MAX_STACK_SIZE - 1);
}

void push(StackType *s, element item) {
    if (is_full(s)) {
        fprintf(stderr, "스택 포화 에러\n");
        exit(1);
    }
    s->data[++(s->top)] = item;
}

element pop(StackType *s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

element peek(StackType *s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    return s->data[s->top];
}
// === 스택 코드 끝 ===


// 연산자의 우선순위 반환 함수
int prec(char op) {
    switch (op) {
        case '(': case ')': return 0;
        case '+': case '-': return 1;
        case '*': case '/': return 2;
    }
    return -1;  // 알 수 없는 연산자
}


// 중위 표기 → 후위 표기 변환 함수
void infix_to_postfix(char exp[]) {
    int i, len = strlen(exp);
    char ch, top_op;
    StackType s;

    init_stack(&s);

    for (i = 0; i < len; i++) {
        ch = exp[i];

        switch (ch) {
            case '+': case '-':
            case '*': case '/':
                while (!is_empty(&s) && prec(ch) <= prec(peek(&s)))
                    printf("%c", pop(&s));
                push(&s, ch);
                break;

            case '(':
                push(&s, ch);
                break;

            case ')':
                top_op = pop(&s);
                while (top_op != '(') {
                    printf("%c", top_op);
                    top_op = pop(&s);
                }
                break;

            default:  // 피연산자인 경우
                printf("%c", ch);
                break;
        }
    }

    // 남아 있는 연산자 모두 출력
    while (!is_empty(&s))
        printf("%c", pop(&s));
}


// 메인 함수
int main(void) {
    char *s = "(2+3)*4+9";
    printf("중위표기식 : %s\n", s);
    printf("후위표기식 : ");
    infix_to_postfix(s);
    printf("\n");

    return 0;
}
