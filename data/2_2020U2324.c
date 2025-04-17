// 📄 파일명: linked_list_search_insert.c

#include <stdio.h>
#include <stdlib.h>

// 노드 구조체 정의
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 새 노드 생성
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

// 특정 값을 가진 노드 탐색
Node* search(Node* head, int target) {
    Node* cur = head;
    while (cur != NULL) {
        if (cur->data == target) {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

// pre 뒤에 새 노드 삽입
void insertAfter(Node* pre, int data) {
    if (pre == NULL) {
        printf("삽입 위치 오류: pre가 NULL입니다.\n");
        return;
    }

    Node* newNode = createNode(data);
    newNode->next = pre->next;
    pre->next = newNode;
}

// 리스트 출력
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

    // 초기 리스트 구성
    head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);

    printf("초기 리스트:\n");
    printList(head);  // 10 -> 20 -> 30 -> NULL

    // 값 20을 가진 노드 찾고 뒤에 25 삽입
    Node* targetNode = search(head, 20);
    if (targetNode) {
        insertAfter(targetNode, 25);
        printf("삽입 후 리스트:\n");
        printList(head);  // 10 -> 20 -> 25 -> 30 -> NULL
    } else {
        printf("노드를 찾을 수 없습니다.\n");
    }

    return 0;
}
