#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

// 정렬 함수 (버블 정렬)
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    FILE *fp;
    int numbers[SIZE];

    // 난수 초기화
    srand(time(NULL));

    // 1~1000 범위의 랜덤 숫자 10개 생성 및 파일 저장
    fp = fopen("input.txt", "w");
    if (fp == NULL) {
        printf("파일을 생성할 수 없습니다.\n");
        return 1;
    }

    printf("생성된 랜덤 숫자 (input.txt에 저장됨):\n");
    for (int i = 0; i < SIZE; i++) {
        numbers[i] = (rand() % 1000) + 1; // 1 ~ 1000 범위의 숫자
        fprintf(fp, "%d ", numbers[i]);
        printf("%d ", numbers[i]);
    }
    printf("\n");

    fclose(fp);

    // 파일에서 숫자 읽기
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    for (int i = 0; i < SIZE; i++) {
        fscanf(fp, "%d", &numbers[i]);
    }
    fclose(fp);

    // 정렬 수행
    bubbleSort(numbers, SIZE);

    // 정렬된 숫자 출력
    printf("정렬된 숫자:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
