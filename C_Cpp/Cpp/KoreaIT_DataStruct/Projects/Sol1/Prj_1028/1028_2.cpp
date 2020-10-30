#include "stdio.h"
#include "iostream"
#include "stdlib.h"


///
/// 그림 반드시 잘 그리고, 숙제 꼭 미리 풀어올 것
/// 

//#define MYSELF
#define TEACHER
#ifdef TEACHER
// 오름차순으로 데이터 추가하기!
// 4번(종료) => 리스트의 모든 노드를 free()하는 함수 FREE() << 를 구현하기!
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
void del(N* root, int data) {
	N* p = root;
	int sw = 1; // 스위치변수 ON
	while (p->next != NULL) {
		if (p->next->data == data) {
			sw = 0; // 스위치변수 OFF
			N* f = p->next; // 삭제할 노드를 가리킬 포인터
			p->next = p->next->next;
			free(f);
			break;
		}
		p = p->next;
	}
	if (sw) {
		printf("없는 데이터입니다!\n");
	}
	else {
		printf("%d 데이터 삭제완료!\n", data);
	}
}
void show(N* root) {
	printf("show(): ");
	N* p = root->next;
	while (p != NULL) {
		printf("%d", p->data);
		p = p->next;
		if (p != NULL) {
			printf("->");
		}
	}
	printf("\n");
}
void FREE(N* root) {
	printf("FREE()수행중...\n");
	N* p = root->next;
	N* f = root->next;
	while (p != NULL) {
		p = p->next; // 순회용포인터 p는 먼저이동
		printf("%d해제 ", f->data);
		free(f);
		f = p; // 공간해제용포인터 f는 p를 따라서 이동
	}
	printf("\nFREE()수행완료\n");
}
int main() {

	N* head = (N*)malloc(sizeof(N));
	head->next = NULL;

	int act;
	while (1) {
		printf("1.노드추가 2.노드삭제 3.리스트출력 4.종료\n");
		printf("번호입력: ");
		scanf("%d", &act);
		if (act == 1) {
			int data;
			printf("정수입력: ");
			scanf("%d", &data);
			add(head, data);
		}
		else if (act == 2) {
			int data;
			printf("정수입력: ");
			scanf("%d", &data);
			del(head, data);
		}
		else if (act == 3) {
			show(head);
		}
		else if (act == 4) {
			printf("프로그램 종료\n");
			break;
		}
		else {
			printf("잘못누르셨습니다.다시 입력하세요.\n");
		}
	}
	FREE(head);
	free(head);

	return 0;
}

#endif


#ifdef MYSELF
typedef struct NODE {
	int data;
	struct NODE* next;
}N;

//1. 없는 데이터입니다!
//2. 중복 데이터입니다!
//3. 오름차순 정렬 //원래 있던것이 더 크다면, insert하면 됨.
//4. 4번(종료) => 리스트의 모든 노드를 free()하는 FREE(head) 함수 만들기

void add(N* root, int data) {
	N* node = (N*)malloc(sizeof(N));
	node->data = data;
	node->next = NULL;
	//node->next -> root; //이거면 뒤로 연결하는거인가?
	//root->next = node; //맨 뒤에 하나씩 차곡차곡 연결해야하는데, 이러면 계속 갱신되어버린다.

	N* p = root; //루트 자체를 준다.
	while (p->next != NULL) { //다음이 가리키는게 NULL이면 마지막 노드임.
		if (p->next->data == data) { //p->data==data는 맹점이 생긴다. 단, p=p->next 뒤에 쓰면 이상없다
			printf("중복된 데이터입니다!\n");
			return;
		}
		p = p->next;
		//Teacher solution : 여기에 if(p->data == data) 검사. 서순이 중요!

		//show의 순회포인터와 조금 다르다. 어쨌든 마지막을 찾는거 아닌가?
	}
	p->next = node; //순회용 포인터가 마지막 노드로 다가가고, 이를 새로 만든 노드와 연결해줌
	printf("%d 데이터 추가 완료\n", data);
}
//숙제 : 항상 오름차순으로 추가될 수 있도록 바꿔오기! 내림차순도 쉬울 듯.

void show(N* root) {
	printf("show(): "); //show 호출 명시
	N* p = root->next; //root가 아닌, root->next부터 본다.
	while (p != NULL) { //p가 NULL이면 마지막 다음임.
		if (p->next != NULL)
			printf("%d->", p->data);
		else if (p->next == NULL)
			printf("%d", p->data);
		p = p->next;
		//teacher solution: if(p == NULL) printf("->");
	}
	printf("\n");
}

void ascAdd(N* root, int data) {
	N* node = (N*)malloc(sizeof(N));
	node->data = data;
	node->next = NULL;

	N* p = root;
	while (p->next != NULL) {
		if (p->next->data > data) {
			//오름차순 정렬조건 걸러냈음.
			break; //위치 찾음
		}
		else if (p->next->data == data) {
			printf("중복된 데이터입니다!\n");
			return;
		}
		p = p->next;
	}
	node->next = p->next->next; //이걸 먼저 해줘야 p->next를 잃어버리지 않음
	p->next = node;
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

void FREE(N* root) {
	printf("FREE() 수행 중...\n");
	N* p = root->next;
	while (p != NULL) {
		N* tmp = p;
		if (p->next == NULL) {
			printf("%d 해제", p->data);
			free(p);
		}
		p = p->next;
	}
}

void main() {
	N* head = (N*)malloc(sizeof(N));
	head->next = NULL;

	int act;
	while (1) {
		//종료조건 아직 구현안함
		printf("1. 노드추가 2. 노드삭제 3. 리스트출력 4. 종료\n");
		printf("번호입력: ");
		scanf("%d", &act);

		if (act == 1) {
			int data;
			printf("정수입력: ");
			scanf("%d", &data);
			//add(head, data); //C컴파일러는 미리 정의된 함수일거라나?
			ascAdd(head, data);
		}
		else if (act == 2) {
			//노드 삭제
			int data;
			printf("정수 입력: ");
			scanf("%d", &data);
			del(head, data); //remove()는 cpp에 이미 있다고 함.
		}
		else if (act == 3) {
			//리스트 출력
			show(head);
		}
		else if (act == 4) {
			printf("프로그램 종료");
			break;
		}
		else {
			printf("잘못 눌렀습니다. 다시 입력하세요 \n");
		}
	}

	FREE(head);
	free(head);
	return;
}
#endif

/* 디버깅표 그리기
 *	Line
 *			head	10	20	30	NULL	
 *	next	10		20	30	NULL	
 *
 */