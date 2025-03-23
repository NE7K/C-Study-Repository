#include <stdio.h>

int main() {
    int numbers[10];      // 10개의 숫자를 저장할 배열
    int sum = 0;          // 합을 저장할 변수
    int max;              // 최대값 저장 변수

    printf("10개의 숫자를 입력하세요 : \n");

    for (int i = 0; i < 10; i++) {
        scanf("%d", &numbers[i]);    // 숫자 입력
        sum += numbers[i];           // 입력하면서 합계 계산

        if (i == 0 || numbers[i] > max) {
            max = numbers[i];        // 최대값 갱신
        }
    }

    printf("입력한 숫자의 합: %d\n", sum);
    printf("입력한 숫자 중 최대값: %d\n", max);

    return 0;
}
