#include<stdio.h>
#include<stdlib.h>
typedef struct NODE {
	int data; // 데이터부
	struct NODE* next; // 주소부==링크부
}N; // 자기참조구조체==노드
int main() {

	// head==root : 데이터부를 이용하지않음
	N* head = (N*)malloc(sizeof(N));
	head->next=NULL; // head.next xxx

	N* node1 = (N*)malloc(sizeof(N));
	node1->data = 1234;
	node1->next = NULL; // 노드생성

	// 리스트화
	head->next = node1; // 노드연결

	N* node2 = (N*)malloc(sizeof(N));
	node2->data = 321;
	node2->next = NULL;
	///
	node1->next = node2;

	// 리스트 출력 -> 순회용포인터==방문용포인터
	N* p = head->next;
	while (p!=NULL) {
		printf("%d ", p->data);
		p = p->next;
	}

	return 0;
}