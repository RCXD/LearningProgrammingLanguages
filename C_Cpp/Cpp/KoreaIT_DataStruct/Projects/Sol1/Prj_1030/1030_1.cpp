//7 3
//3 6 2 7 5 1 4
//삭제연산문제: 배열이 아닌, 링크드리스트를 쓰는게 맞다..

#include "stdio.h"
#include "iostream"

#define MYSELF
//#define TEACHER
#ifdef TEACHER
// 7 3
// 3 6 2 7 5 1 4
#include<stdio.h>
#include<stdlib.h>
typedef struct NODE {
	int data;
	struct NODE* next;
}N;
void add(N* root, int data) {
	N* node = (N*)malloc(sizeof(N));
	node->data = data;
	node->next = NULL;
	N* p = root;
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = node;
}
void add2(N* root, int data) {
	N* node = (N*)malloc(sizeof(N));
	node->data = data;
	node->next = NULL;
	N* p = root;
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = node;
	node->next = root->next; // 사이클을 생성!
}
int main() {

	int a, b;
	scanf("%d%d", &a, &b);
	// h->1->2->3-> ... -> 7

	N* head = (N*)malloc(sizeof(N));
	head->next = NULL;
	for (int i = 0; i < a - 1; i++) {
		add(head, i + 1);
	}
	add2(head, a);

	N* p = head;
	int cnt = 0;
	int c = 0;
	while (c != a) {
		cnt++;
		if (cnt == b) {
			c++;
			cnt = 0;
			printf("%d ", p->next->data);
			p->next = p->next->next;
			continue;
		}
		p = p->next;
	}
	printf("\n\n");
	/*
	N* p = head->next;
	while (p!=NULL) {
	   printf("%d ", p->data);
	   p = p->next;
	}
	*/

	return 0;
}

#endif

#ifdef MYSELF
typedef struct NODE {
	int data;
	struct NODE* next;
}N;
void add(N* root, int data) {
	N* node = (N*)malloc(sizeof(N));
	node->data = data;
	node->next = NULL;
	N* p = root; // 리스트의 마지막노드를 찾는 순회용포인터
	while (p->next != NULL) {
		if (p->next->data > data) {
			// 오름차순입력시, 제대로된 위치를 찾음!
			node->next = p->next;
			break;
		}
		p = p->next;
		if (p->data == data) {
			printf("중복 데이터입니다!\n");
			return;
		}
	}
	p->next = node;
	printf("%d 데이터 추가완료!\n", data);
}

void add2(N* root, int data) {
	N* node = (N*)malloc(sizeof(N));
	node->data = data;
	node->next = NULL;
	N* p = root; // 리스트의 마지막노드를 찾는 순회용포인터
	while (p->next != NULL) {
		if (p->next->data > data) {
			// 오름차순입력시, 제대로된 위치를 찾음!
			node->next = p->next;
			break;
		}
		p = p->next;
		if (p->data == data) {
			printf("중복 데이터입니다!\n");
			return;
		}
	}
	p->next = node;
	node->next = root->next;//사이클 생성
	printf("%d 데이터 추가완료!\n", data);
}

//삭제가 해야 할 일 : 연결을 끊는다.
void del(N* root, int data) { //삭제가 안되고 있는데?? 확인좀??
	//N* p = root->next; //show에서 이런 이유는 root에 데이터가 없기 때문.
	//root->next부터 시작하면, 헤드 바로 다음(첫번째)을 삭제하고 싶을 때 삭제하기 곤란해진다.
	N* p = root; //
	while (p->next != NULL) { //마지막 노드까지 오기 전까지 순환
		//if (현재 p가 가리키는 노드'가 가리키는' 데이터가 삭제할 데이터일때) { //Sudo coding? 수동코딩?
		if (p->next->data == data) {//중간에, 조건을 만족할 때(타겟 앞에 도달했을 때)
			//free(p->next); //여기서 하면 next->next가 이상한데로 가버림
			N* f = p->next; //삭제대상을 가리킬 포인터
			p->next = p->next->next; //p->next를 무시해버림!
			//free(p->next); //여기서도 그냥은 삭제 대상을 더이상 가리킬 수 없다.
			free(f);
			return;
		}
		p = p->next; //타겟 못찾았으면 진행
	}
	printf("없는 데이터입니다!\n");
}

void main() {
	int a, b;
	scanf("%d%d", &a, &b);
	//h->1->2->...->7

	N* head = (N*)malloc(sizeof(N));
	head->next=NULL;

	for (int i = 1; i < a/*a-1*/; i++) {
		add(head, i);
	}
	//cycle이 있는 리스트로 만들어주어야 한다. 마지막노드 추가는 별도 구현해야 함.
	add2(head, a);

	//N* p = head->next;
	int cnt = b+1;
	while (1) {
		if (--cnt == 0) {
			printf("%d ", p->next->data);
			N* f = p->next;
			p->next = p->next->next;
			free(f);
			cnt == b + 1;
		}
		p = p->next;
	} //뭔가 잘못만들었음. 5->3->6->7->2->4->1, 무한루프. 수정바람
	///수리좀!!
	///
	/*
	N* p = head->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	*/
	

	return;
}
#endif

/* 디버깅표 그리기
 *	Line
 *
 *
 *
 */