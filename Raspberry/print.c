#include <stdio.h>

int main() {
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    int numbers[10];

    for (int i = 0; i < 10; i++) {
        if (fscanf(fp, "%d", &numbers[i]) != 1) {
            printf("파일 읽기 오류!\n");
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);

    printf("파일에서 읽어온 숫자:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}