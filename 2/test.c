#include <stdio.h>

int main() {

    // - 키보드에서 자신의 주민 등록 번호 앞 6자리를 입력 밭아 화면에 출력하라.
    // - 이어서 자신의 영문 이름을 입력 받아 화면에 출력하라.

    char number[100], name_EN[100];

    printf("주민등록번호 앞 6자리 입력: ");
    scanf("%6s", number);

    printf("영문 이름 입력: ");
    scanf("%s", name_EN);

    printf("\n입력된 주민등록번호: %s\n", number);
    printf("입력된 영문 이름: %s\n", name_EN);

    return 0;

}