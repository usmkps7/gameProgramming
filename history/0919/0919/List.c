#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// 연결 리스트 노드 구조체
struct linked_list {
    char data;
    struct linked_list *link;    
};
struct linked_list *head = NULL; // 연결 리스트 헤드 포인터

// 스택 노드 구조체
struct stack_node {
    char data;
    struct stack_node *link;
};
struct stack_node *top = NULL;   // 스택 top 포인터

// 연결 리스트에 노드 추가
void add_node(char data){
    struct linked_list *new_node, *last;
    if (head == NULL) { // 비어있으면 첫 노드 생성
        head = (struct linked_list*)malloc(sizeof(struct linked_list));
        head->data = data;
        head->link = NULL;
        return;
    }

    last = head;
    while(last->link != NULL)
        last = last->link;

    new_node = (struct linked_list*)malloc(sizeof(struct linked_list));
    new_node->data = data;
    new_node->link = NULL;
    last->link = new_node;
}

// 스택 push
void push(char data){
    struct stack_node *new_node;
    new_node = (struct stack_node*)malloc(sizeof(struct stack_node));
    new_node->data = data;
    new_node->link = top;
    top = new_node;
}

// 스택 pop
char pop(void){
    struct stack_node *temp;
    char data;

    if (top == NULL) return '\0'; // 빈 스택 방지

    data = top->data;
    temp = top;
    top = top->link;
    free(temp);

    return data;
}

int main(void){
    SetConsoleOutputCP(65001); // UTF-8 설정

    int count = 0;
    char key;

    do {
        count++;
        printf("%2d 번 문자입력 >", count);
        key = getch();   // 키보드 입력
        push(key);
        printf("%c \n", key);
    } while(key != 27);  // ESC 입력 시 종료

    printf("\n\n데이터 pop과정 \n\n");
    while (top != NULL) {
        key = pop();
        printf("%c ", key);
    }
    printf("\n");

    return 0;
}
