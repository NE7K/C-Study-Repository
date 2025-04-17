#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10      // 최대 단어 개수
#define WORD_LEN 100     // 단어 최대 길이

int main() {
    FILE *file;
    char words[MAX_SIZE][WORD_LEN];
    int count = 0;
    char max1[WORD_LEN], max2[WORD_LEN];

    file = fopen("inputData.txt", "r");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    // 최대 MAX_SIZE개의 단어를 파일에서 읽음
    while (fscanf(file, "%s", words[count]) == 1 && count < MAX_SIZE) {
        count++;
    }

    fclose(file);

    if (count == 0) {
        printf("파일에 데이터가 없습니다.\n");
        return 1;
    } else if (count == 1) {
        printf("입력된 단어 개수: 1\n");
        printf("최대 단어(사전 순): %s\n", words[0]);
        printf("두 번째로 큰 단어가 없습니다.\n");
        return 0;
    }

    // 첫 두 단어로 초기화
    if (strcmp(words[0], words[1]) > 0) {
        strcpy(max1, words[0]);
        strcpy(max2, words[1]);
    } else {
        strcpy(max1, words[1]);
        strcpy(max2, words[0]);
    }

    // 나머지 단어들 비교
    for (int i = 2; i < count; i++) {
        if (strcmp(words[i], max1) > 0) {
            strcpy(max2, max1);
            strcpy(max1, words[i]);
        } else if (strcmp(words[i], max2) > 0 && strcmp(words[i], max1) != 0) {
            strcpy(max2, words[i]);
        }
    }

    // 결과 출력
    printf("입력된 단어 개수: %d\n", count);
    printf("최대 단어(사전 순): %s\n", max1);
    printf("두 번째로 큰 단어(사전 순): %s\n", max2);

    return 0;
}