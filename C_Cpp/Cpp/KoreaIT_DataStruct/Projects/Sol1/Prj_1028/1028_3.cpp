#include "stdio.h"
#include "stdlib.h"
#include "iostream"

//#define MYSELF
#define TEACHER
#ifdef TEACHER

typedef struct stu {
	char name[10];
	int num;
	int score[2];
	double avg;
	char grade;
}S;
typedef struct NODE {
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
		printf("시험%d성적: ", i + 1);
		scanf("%d", &node->data.score[i]);
	}
	N* p = root;
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = node;
}
void del(N* root, int num) {
	N* p = root;
	int sw = 1;
	while (p->next != NULL) {
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
void modi(N* root, int num) {
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
void show(N* root) {
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
			del(head, num);
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


#endif


#ifdef MYSELF
typedef struct stu {
	char name[10];
	int num;
	int score[2];
	double avg;
	char grade;
}S;
typedef struct NODE {
	S data; //공간을 만들어둔것 뿐임. 멤버접근도 가능
	struct NODE* next;
}N;

void add(N* root) {
	static int num = 1001; //main의 지역변수를 add의 정적변수로.
	//고유값이 있으면 중복범위판단이 불필요할수도.
	//함수 실행횟수 따질 때 static변수를 많이 쓴다!
	//확실하게 num은 add에서만 쓸 예정이라는 얘기. 고유값이므로 삭제 등 다른 옵션에서도 무관함.
	//조건이 조금 까다롭다는것.
	N* node = (N*)malloc(sizeof(N));
	node->next = NULL;
	printf("학생이름: ");
	scanf("%s", node->data.name);
	node->data.num = num++;
	for (int i = 0; i < 2; i++) {
		printf("시험%d의 성적: ", i + 1);
		scanf("%s", &node->data.score[i]);
	}
	N* p = root;
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = node;
}

void show(N* root) {
	N* p = root->next; //head에는 데이터가 없으므로 굳이 root부터 볼 필요 없다.
	while (p != NULL) {
		printf("%d. %-5s 학생\n", p->data.num, p->data.name); //형식지정자로 정렬~!
		p = p->next;
	}
}

void del(N* root, int num) { //티처 코드 확인바람
	int sw = 1;
	N* p = root; //삭제할 데이터보다 앞에 있어야함.
	while (p->next != NULL) {
		if (p->next->data.num == num) {
			sw = 0;
			N* f = p->next;
			p->next = p->next->next;
			free(f);
			//
			break;
		}
		p = p->next;
	}
	if (sw) {
		printf("없는 학생입니다!\n");
	}
	else {
		printf("삭제 완료!\n");//? free(f)밑에서 하고싶은디
	}
}

void modi(N* root, int num) {
	//이름바꾸기, 성적바꾸기 중 이름바꾸기만 일단 구현
	N* p = root->next; //연결을 새로 할 필요 없으므로 show처럼.
	while (p != NULL) {
		if (p->data.num == num) {
			printf("학생이름: ");
			scanf("%s", &p->data.name);
			//이 아래부터 티처 코드 확인바람
			p->next = p->next->next;

			//
			break;
		}
		p = p->next;
	}
	if (sw) {
		printf("없는 학생입니다!\n");
	}
	else {
		printf("수정 완료!\n");//? free(f)밑에서 하고싶은디
	}
}

void main() {
	N* head = (N*)malloc(sizeof(N));
	head->next = NULL; //의미없는 곳엔 NULL처리를 꼭 해주어야 함. 그래야 마지막 노드임을 검출할 수 있음

	//int num = 1001;//main에서 선언하던지, static으로 함수 내에서 쓰던지.

	int act;
	while (1) {
		printf("===학생부===\n");
		printf("1.추가 2. 삭제 3. 수정 4. 출력 5. 종료\n");
		printf("번호 입력: ");
		scanf(" %d", &act);

		if (act == 1) {
			add(head);
		}
		else if (act == 2) {
			int num;
			printf("삭제할 학생의 번호 입력: ");
			scanf("%d", &num);
			//범위 제어하기
			if (num <= 1000 || num >= 2000) {
				printf("임력범위가 아닙니다!\n");
				continue;
			}
			del(head, num);
		}
		else if (act == 3) {
			modi(head, num);
		}
		else if (act == 4) {
			show(head);
		}
		else if (act == 5) {

		}
		else {
		}
	}

	return;
}

#endif

/* 디버깅표 그리기
 *	Line
 *
 *
 *
 */