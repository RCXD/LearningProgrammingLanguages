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

//1. 없는 데이터입니다!
//2. 중복 데이터입니다!
//3. 오름차순 정렬
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
	printf("%d 데이터 추가 완료\n",data);
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
			add(head, data); //C컴파일러는 미리 정의된 함수일거라나?
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
	free(head);
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
 *			head	10	20	30	NULL	
 *	next	10		20	30	NULL	
 *
 */