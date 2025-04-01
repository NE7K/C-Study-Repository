#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000  // 배열 최대 크기

int main() {
    FILE *file;
    int data[MAX_SIZE];
    int count = 0;
    int max;

    file = fopen("inputData.txt", "r");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    // 파일에서 정수를 읽어 배열에 저장
    while (fscanf(file, "%d", &data[count]) == 1 && count < MAX_SIZE) {
        count++;
    }

    fclose(file);

    if (count == 0) {
        printf("파일에 데이터가 없습니다.\n");
        return 1;
    }

    // 최대값 찾기
    max = data[0];
    for (int i = 1; i < count; i++) {
        if (data[i] > max) {
            max = data[i];
        }
    }

    // 결과 출력
    printf("입력된 정수 개수: %d\n", count);
    printf("최대값: %d\n", max);

    return 0;
}
