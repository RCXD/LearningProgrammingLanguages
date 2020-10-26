#include "stdio.h"
#include "iostream"
#include "stdlib.h"

//#define MYSELF
#define TEACHER
#ifdef TEACHER
typedef struct NODE {
	int data; // 데이터부
	struct NODE* next; //주소부 == 링크부
}N; //자기참조구조체 ==노드 //말만 대단하지 그냥 노드자료형을 가리키는 포인터 하나 포함한거 뿐인거같은데?
//메모리 크기를 미리 계산하는 컴파일러 수준에서는 신경써야 하려나.(아닐거 같긴 하다.)

//리스트를 구성하고있는 단위: 노드


void main() {

	//head==root
	N* head = (N*)malloc(sizeof(N)/* *1 */); //크기 1개라는건 생략. head가 1칸짜리 공간을 가리키게 된다.
	head->next = NULL; //head.next는 아님! 구조체 멤버접근연산자임. 포인터 멤버접근은 ->를 사용

	//노드 생성
	N* node1 = (N*)malloc(sizeof(N));
	node1->data = 10;
	node1->next = NULL;

	//리스트화 과정 필요.
	head->next = node1;

	//노드 생성
	N* node2 = (N*)malloc(sizeof(N));
	node2->data = 20;
	node2->next = NULL;

	//연결
	node1->next = node2;

	//리스트 '방문용' 포인터==순회용 포인터
	N* curr = head->next;
	//리스트 데이터 출력
	while (curr !=NULL) //curr->next == NULL일 시점에서 curr == NULL이 됨
	{
		printf("%d ", curr->data);
		curr = curr->next;
	}
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