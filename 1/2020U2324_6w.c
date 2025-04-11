#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10  // 읽을 최대 정수 개수를 10개로 제한

// 내림차순 정렬 함수 (버블 정렬 사용)
void sortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] < arr[j + 1]) {
                // swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    FILE *file;
    int data[MAX_SIZE];
    int count = 0;

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
    }

    // 정렬
    sortDescending(data, count);

    // 정렬된 결과 화면에 출력
    printf("입력된 정수 개수: %d\n", count);
    printf("내림차순 정렬 결과:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    // 정렬된 결과 output.txt에 저장
    FILE *outFile = fopen("output.txt", "w");
    if (outFile == NULL) {
        printf("output.txt 파일을 생성할 수 없습니다.\n");
        return 1;
    }

    for (int i = 0; i < count; i++) {
        fprintf(outFile, "%d ", data[i]);
    }

    fclose(outFile);
    printf("정렬된 결과가 output.txt 파일에 저장되었습니다.\n");

    return 0;
}
