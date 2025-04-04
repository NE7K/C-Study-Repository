#include <stdio.h>
#include <ctype.h>

int main() {
    char str[100], ch, next_ch;
    int count = 1, i = 0;

    printf("문자열을 입력하시오: ");
    scanf("%s", str);

    printf("압축된 문자열: ");

    while (str[i] != '\0') {
        ch = tolower(str[i]);
        count = 1;

        // peek 연산과 유사하게 다음 문자 미리 확인
        while (str[i + 1] != '\0' && tolower(str[i + 1]) == ch) {
            count++;
            i++;
        }

        printf("%d%c", count, ch);
        i++;
    }

    printf("\n");
    return 0;
}