#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10  // 읽을 최대 정수 개수를 10개로 제한

int main() {
    FILE *file;
    int data[MAX_SIZE];
    int count = 0;
    int max1, max2;

    file = fopen("inputData.txt", "r");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    // 최대 10개 정수를 파일에서 읽음
    while (fscanf(file, "%d", &data[count]) == 1 && count < MAX_SIZE) {
        count++;
    }

    fclose(file);

    if (count == 0) {
        printf("파일에 데이터가 없습니다.\n");
        return 1;
    } else if (count == 1) {
        printf("입력된 정수 개수: 1\n");
        printf("최대값: %d\n", data[0]);
        printf("두 번째로 큰 값이 없습니다.\n");
        return 0;
    }

    // 최대값과 두 번째 최대값 찾기
    if (data[0] > data[1]) {
        max1 = data[0];
        max2 = data[1];
    } else {
        max1 = data[1];
        max2 = data[0];
    }

    for (int i = 2; i < count; i++) {
        if (data[i] > max1) {
            max2 = max1;
            max1 = data[i];
        } else if (data[i] > max2) {
            max2 = data[i];
        }
    }

    // 결과 출력
    printf("입력된 정수 개수: %d\n", count);
    printf("최대값: %d\n", max1);
    printf("두 번째로 큰 값: %d\n", max2);

    return 0;
}
