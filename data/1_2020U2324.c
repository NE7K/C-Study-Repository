// 📄 파일명: linked_list_test.c

#include <stdio.h>
#include <stdlib.h>

// 노드 구조체 정의
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 새 노드 생성 함수
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("메모리 할당 실패\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// head 앞에 새 노드 삽입 (head 변경 후 반환)
Node* insertFront(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// 연결 리스트 전체 출력
void printList(Node* head) {
    Node* cur = head;
    while (cur != NULL) {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

// 테스트
int main() {
    Node* head = NULL;

    // 앞에 차례로 삽입
    head = insertFront(head, 30);
    head = insertFront(head, 20);
    head = insertFront(head, 10);

    printf("단순 연결 리스트 테스트 결과:\n");
    printList(head);  // 10 -> 20 -> 30 -> NULL

    return 0;
}
