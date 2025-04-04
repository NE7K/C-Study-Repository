#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

// 프로그램 4.3에서 stack 구조체와 관련 함수가 정의되어 있어야 함
// typedef와 push, pop 함수 등...

typedef int element;

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

// 후위 표기 계산 함수
int eval(char exp[]) {
    int op1, op2, value, i = 0;
    int len = strlen(exp);
    char ch;
    StackType s;

    init_stack(&s);

    for (i = 0; i < len; i++) {
        ch = exp[i];

        if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
            value = ch - '0';  // 피연산자면 숫자로 변환
            push(&s, value);
        }
        else {
            op2 = pop(&s);
            op1 = pop(&s);

            switch (ch) {
                case '+': push(&s, op1 + op2); break;
                case '-': push(&s, op1 - op2); break;
                case '*': push(&s, op1 * op2); break;
                case '/': push(&s, op1 / op2); break;
            }
        }
    }

    return pop(&s);
}

int main(void) {
    int result;

    printf("후위표기식은 82/3-32*+\n");
    result = eval("82/3-32*+");
    printf("계산 결과는 %d\n", result);

    return 0;
}
