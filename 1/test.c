#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void sortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    FILE *file = fopen("inputData.txt", "r");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    int data[MAX_SIZE];
    int count = 0;

    // 최대 10개 정수 읽기
    while (fscanf(file, "%d", &data[count]) == 1 && count < MAX_SIZE) {
        count++;
    }
    fclose(file);

    if (count == 0) {
        printf("파일에 데이터가 없습니다.\n");
        return 1;
    }

    // 내림차순 정렬
    sortDescending(data, count);

    // 출력
    printf("입력된 정수 개수: %d\n", count);
    printf("내림차순 정렬 결과:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    // 결과 저장
    FILE *outFile = fopen("output.txt", "w");
    if (outFile == NULL) {
        printf("output.txt 파일 생성 실패\n");
        return 1;
    }
    for (int i = 0; i < count; i++) {
        fprintf(outFile, "%d ", data[i]);
    }
    fclose(outFile);

    printf("정렬 결과 저장 완료\n");
    return 0;
}
