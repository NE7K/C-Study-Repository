#include <stdio.h>

int main() {
    int numbers[7];
    int sum = 0;          // 합을 저장할 변수
    int max, min;         // 최대값과 최소값 저장 변수

    printf("7개의 숫자를 입력하세요 : \n");

    for (int i = 0; i < 7; i++) {
        scanf("%d", &numbers[i]);    // 숫자 입력
        sum += numbers[i];           // 입력하면서 합계 계산

        if (i == 0) {
            max = min = numbers[i];  // 첫 번째 숫자로 초기화
        } else {
            if (numbers[i] > max) {
                max = numbers[i];    // 최대값 갱신
            }
            if (numbers[i] < min) {
                min = numbers[i];
            }
        }
    }

    printf("첫째줄 합 : %d\n", sum);   // 첫째 줄: 합
    printf("둘째줄 최대값 : %d\n", max);   // 둘째 줄: 최대값
    printf("셋째줄 최소값 : %d\n", min);   // 셋째 줄: 최소값

    return 0;
}
