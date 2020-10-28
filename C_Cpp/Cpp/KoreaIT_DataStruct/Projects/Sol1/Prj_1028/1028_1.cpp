#include "stdio.h"
#include "iostream"
#include "stdlib.h"

//#define MYSELF
#define TEACHER
#ifdef TEACHER

typedef struct NODE {
	int data;
	struct NODE* next;
}N;

void main() {
	N* head = (N*)malloc(sizeof(N));
	head->next = NULL;
	
	N* node1 = (N*)malloc(sizeof(N));
	node1->data = 100;
	node1->next = NULL;

	head->next = node1;

	N* node2 = (N*)malloc(sizeof(N));
	node2->data = 200;
	node2->next = NULL;

	node1->next = node2;
	
	//방문용 포인터==순회용 포인터
	N* p = head->next; 
	//헤드의 데이터는 비어있으므로 가리키는게 의미가 없음.
	//헤드의 다음, 즉 node1을 먼저 가리킴
	//head를 이용해서 node1을 가리키는 이유는, 
	//node1, 2를 더이상 명시적으로 가리킬 수 없을 예정이기 때문인듯.
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}

	free(head);
	free(node1);
	free(node2);
	return;
}

#endif


#ifdef MYSELF
void main() {


	return;
}
#endif

/* 디버깅표 그리기
 *	Line
 *
 *
 *
 */