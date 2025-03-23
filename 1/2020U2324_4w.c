#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// 함수 선언
void readFile(const char* filename, int arr[]);
void printArray(const int arr[], int size);
void andOperation(const int a[], const int b[]);
void orOperation(const int a[], const int b[]);
void xorOperation(const int a[], const int b[]);
int isInArray(int arr[], int size, int value);

int main() {
    int A[SIZE], B[SIZE];
    int choice;

    while (1) {
        // 파일에서 숫자 읽기
        readFile("A.txt", A);
        readFile("B.txt", B);

        // 메뉴 출력
        printf("\n====== 집합 연산 메뉴 ======\n");
        printf("1. AND (교집합)\n");
        printf("2. OR (합집합)\n");
        printf("3. XOR (차집합)\n");
        printf("4. Quit (종료)\n");
        printf("선택 (1-4) : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n[AND - 교집합 결과]:\n");
                andOperation(A, B);
                break;
            case 2:
                printf("\n[OR - 합집합 결과]:\n");
                orOperation(A, B);
                break;
            case 3:
                printf("\n[XOR - 차집합 결과]:\n");
                xorOperation(A, B);
                break;
            case 4:
                printf("프로그램을 종료합니다.\n");
                return 0;
            default:
                printf("잘못된 입력입니다. 1~4 중 선택하세요.\n");
        }
    }
    return 0;
}

// 파일에서 숫자 읽기
void readFile(const char* filename, int arr[]) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("파일 열기 실패");
        exit(1);
    }
    for (int i = 0; i < SIZE; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);
}

// 배열에 특정 값이 있는지 확인
int isInArray(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) return 1;
    }
    return 0;
}

// 교집합
void andOperation(const int a[], const int b[]) {
    for (int i = 0; i < SIZE; i++) {
        if (isInArray((int*)b, SIZE, a[i])) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

// 합집합
void orOperation(const int a[], const int b[]) {
    int result[2 * SIZE], index = 0;

    // A 배열 복사
    for (int i = 0; i < SIZE; i++) {
        result[index++] = a[i];
    }

    // B에서 A에 없는 값만 추가
    for (int i = 0; i < SIZE; i++) {
        if (!isInArray(a, SIZE, b[i])) {
            result[index++] = b[i];
        }
    }

    // 출력
    for (int i = 0; i < index; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

// 차집합 (A - B, B - A 모두 포함한 대칭차)
void xorOperation(const int a[], const int b[]) {
    // A 중 B에 없는 것
    for (int i = 0; i < SIZE; i++) {
        if (!isInArray((int*)b, SIZE, a[i])) {
            printf("%d ", a[i]);
        }
    }

    // B 중 A에 없는 것
    for (int i = 0; i < SIZE; i++) {
        if (!isInArray((int*)a, SIZE, b[i])) {
            printf("%d ", b[i]);
        }
    }

    printf("\n");
}
