// 1.예매 2.입장 3.종료

// 1) 대기열 큐에 사람 1명추가
// 사람: 이름,예매번호,영화제목
// 어떤 영화를 보시겠습니까? 2
//  [1.aaa 2.bbb 3.ccc]
// 예약자 성함입력: 홍길동
// 예매번호를 랜덤으로 지정 출력 1001~9999
// "홍길동님, bbb영화 [1234]입니다."

// 2) 몇명입장? (큐의 사이즈보다 더 큰입력시, 불가능하다는 안내출력!)
// 홍길동님, 예매번호는? 1234
// bbb 즐거운 관람되세요~!!
// 임꺽정님, 예매번호는? 1111
// 입장불가!
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 3
typedef struct Per {
	int data;
	char movie[30];
	char name[30];
}P;
typedef struct NODE {
	P data;
	struct NODE* next;
}N;
typedef struct Queue {
	N* front;
	N* rear;
	int size;
}Q;
char MT[MAX][30] = { "삼진","다만악","소리도" };
void Enqueue(Q* q) {
	N* node = (N*)malloc(sizeof(N));
	node->data.data= rand() % 8999 + 1001;
	for (int i = 0; i < MAX; i++) {
		printf("%d.%s ", i + 1, MT[i]);
	}
	printf("\n어떤 영화를 보시겠습니까? ");
	int num;
	scanf("%d", &num);
	num--;
	// node->data.movie = MT[num]; xxx
	strcpy(node->data.movie, MT[num]);
	// strcpy(A,B); << B의 문자열값을 A의 문자열공간에 저장하는 함수
	printf("예약자 성함입력: ");
	scanf("%s", node->data.name);
	node->next = NULL;
	printf("%s님, %s영화 [%d]입니다.\n", node->data.name, node->data.movie, node->data.data);
	// 노드생성

	// 큐에 Enqueue()
	if (q->size == 0) {
		q->front = node;
	}
	else {
		q->rear->next = node;
	}
	q->rear = node;
	q->size++;
}
void Dequeue(Q* q) {
	int n;
	printf("%s님, 예매번호는? ",q->front->data.name);
	scanf("%d", &n);
	if (n == q->front->data.data) {
		printf("%s 즐거운 관람되세요~!!\n", q->front->data.movie);
		q->front = q->front->next;
		q->size--;
	}
	else {
		q->rear->next = q->front;
		q->front = q->front->next;
		q->rear = q->rear->next;
		q->rear->next = NULL;
		printf("입장불가!\n");
	}
}
int main() {

	// rand() % 8999 + 1001;
	Q q;
	q.front = NULL;
	q.rear = NULL;
	q.size = 0;

	while (1) {
		int act;
		printf("1.예매 2.입장 3.종료  ");
		scanf("%d", &act);
		if (act == 1) {
			Enqueue(&q);
		}
		else if (act == 2) {
			printf("몇명입장하시겠습니까? ");
			int n;
			scanf("%d", &n);
			if (q.size < n) {
				printf("대기자보다 많습니다!\n");
				continue;
			}
			for (int i = 0; i < n; i++) {
				Dequeue(&q);
			}
		}
		else {
			printf("프로그램종료...\n");
			break;
		}
	}

	return 0;
}