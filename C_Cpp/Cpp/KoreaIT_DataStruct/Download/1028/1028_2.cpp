#include<stdio.h>
#include<stdlib.h>
typedef struct stu {
	char name[10];
	int num;
	int score[2];
	double avg;
	char grade;
}S;
typedef struct NODE{
	S data;
	struct NODE* next;
}N;
void add(N* root) {
	static int num = 1001;
	N* node = (N*)malloc(sizeof(N));
	node->next = NULL;
	printf("학생이름: ");
	scanf("%s", node->data.name);
	node->data.num = num++;
	for (int i = 0; i < 2; i++) {
		printf("시험%d성적: ",i+1);
		scanf("%d", &node->data.score[i]);
	}
	N* p = root;
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = node;
}
void del(N *root,int num) {
	N* p = root;
	int sw = 1;
	while (p->next!=NULL) {
		if (p->next->data.num == num) {
			sw = 0;
			N* f = p->next;
			p->next = p->next->next;
			free(f);
			break;
		}
		p = p->next;
	}
	if (sw) {
		printf("없는 학생입니다!\n");
	}
	else {
		printf("삭제 완료!\n");
	}
}
void modi(N *root, int num) {
	N* p = root->next;
	int sw = 1;
	while (p != NULL) {
		if (p->data.num == num) {
			sw = 0;
			printf("학생이름: ");
			scanf("%s", p->data.name);
			break;
		}
		p = p->next;
	}
	if (sw) {
		printf("없는 학생입니다!\n");
	}
	else {
		printf("수정 완료!\n");
	}
}
void show(N *root) {
	N* p = root->next;
	while (p != NULL) {
		printf("%d. %-5s학생\n", p->data.num, p->data.name);
		p = p->next;
	}
}
int main() { 
	
	N* head = (N*)malloc(sizeof(N));
	head->next = NULL;

	int act;
	while (1) {
		printf("===학생부===\n");
		printf("1.추가 2.삭제 3.수정 4.출력 5.종료\n");
		printf("번호입력: ");
		scanf("%d", &act);
		if (act == 1) {
			add(head);
		}
		else if (act == 2) {
			int num;
			printf("삭제할학생의 번호입력: ");
			scanf("%d", &num);
			if (num <= 1000 || num >= 2000) {
				printf("입력범위가 아닙니다!\n");
				continue;
			}
			del(head,num);
		}
		else if (act == 3) {
			int num;
			printf("수정할학생의 번호입력: ");
			scanf("%d", &num);
			if (num <= 1000 || num >= 2000) {
				printf("입력범위가 아닙니다!\n");
				continue;
			}
			modi(head, num);
		}
		else if (act == 4) {
			show(head);
		}
		else {
			break;
		}
	}

	return 0;
}