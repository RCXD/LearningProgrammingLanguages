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
			N* f=p->next; // 삭제할 노드를 가리킬 포인터
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
	//FREE(head);

	return 0;
}