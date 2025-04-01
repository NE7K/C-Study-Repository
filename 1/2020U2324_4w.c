#include <stdio.h>
#include <stdlib.h>

#define SIZE_A 5
#define SIZE_B 4

// 함수 선언
void readFile(const char* filename, int arr[], int size);
void printArray(const int arr[], int size);
void xorOperation(const int a[], const int b[], int sizeA, int sizeB); // 차집합 먼저
void andOperation(const int a[], const int b[], int sizeA, int sizeB); // 그다음 교집합
void orOperation(const int a[], const int b[], int sizeA, int sizeB);
int isInArray(int arr[], int size, int value);

int main() {
    int A[SIZE_A], B[SIZE_B];
    int choice;

    printf("\n====== 집합 연산 메뉴 ======\n");
    printf("1. XOR (차집합)\n"); // 변경된 순서
    printf("2. AND (교집합)\n");
    printf("3. OR (합집합)\n");
    printf("4. Quit (종료)\n");

    while (1) {
        printf("\n선택 (1-4) : ");
        scanf("%d", &choice);

        readFile("A.txt", A, SIZE_A);
        readFile("B.txt", B, SIZE_B);

        switch (choice) {
            case 1:
                printf("\n[XOR - 차집합 결과]:\n");
                xorOperation(A, B, SIZE_A, SIZE_B);
                break;
            case 2:
                printf("\n[AND - 교집합 결과]:\n");
                andOperation(A, B, SIZE_A, SIZE_B);
                break;
            case 3:
                printf("\n[OR - 합집합 결과]:\n");
                orOperation(A, B, SIZE_A, SIZE_B);
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

void readFile(const char* filename, int arr[], int size) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("파일 열기 실패");
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);
}

int isInArray(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) return 1;
    }
    return 0;
}

// XOR: A - B + B - A
void xorOperation(const int a[], const int b[], int sizeA, int sizeB) {
    for (int i = 0; i < sizeA; i++) {
        if (!isInArray((int*)b, sizeB, a[i])) {
            printf("%d ", a[i]);
        }
    }

    for (int i = 0; i < sizeB; i++) {
        if (!isInArray((int*)a, sizeA, b[i])) {
            printf("%d ", b[i]);
        }
    }
    printf("\n");
}

// AND: 교집합
void andOperation(const int a[], const int b[], int sizeA, int sizeB) {
    for (int i = 0; i < sizeA; i++) {
        if (isInArray((int*)b, sizeB, a[i])) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

// OR: 합집합
void orOperation(const int a[], const int b[], int sizeA, int sizeB) {
    int result[SIZE_A + SIZE_B], index = 0;

    for (int i = 0; i < sizeA; i++) {
        result[index++] = a[i];
    }

    for (int i = 0; i < sizeB; i++) {
        if (!isInArray((int*)a, sizeA, b[i])) {
            result[index++] = b[i];
        }
    }

    for (int i = 0; i < index; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}
