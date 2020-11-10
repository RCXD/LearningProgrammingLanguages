// 1. 큐 전체 크기제한이 없다.
// 2. 0값을 입력할수있다.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct NODE {
	int data;
	struct NODE* next;
}N;
typedef struct Queue {
	N* front;
	N* rear;
	int size;
}Q;
void Enqueue(Q *q, int data) {
	N* node = (N*)malloc(sizeof(N));
	node->data = data;
	node->next = NULL;
	// 노드생성

	// 생성한 노드를 큐에 연결하기!
	if (q->size == 0) {
		// 큐가 비어있으니,
		// 맨 앞을 현재 노드로 설정해라.
		q->front = node;
	}
	else {
		q->rear->next = node;
	}
	q->rear = node;
	q->size++;
}
int Dequeue(Q *q) {
	N* p = q->front;
	q->front = q->front->next;
	int res = p->data;
	free(p);
	q->size--;
	return res;
}
void show(Q q) {
	printf("show()호출!\n");
	N* p = q.front;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
void roll(Q *q) {
	// 포인터들을 오른쪽으로 1칸씩 이동
	// 데이터들은 왼쪽으로 1칸씩 이동하는 효과
	
	// 10f->20->30r   =>   10->20f->30->10r->20->...
	q->rear->next = q->front;

	q->rear = q->rear->next;
	q->front = q->front->next;

	q->rear->next = NULL;
}
int main() {

	Q q;
	q.front = NULL;
	q.rear = NULL;
	q.size = 0;

	char act[15];
	while (1) {
		printf("1.Enqueue() 2.Dequeue() 3.show() 4.roll() 5.종료\n");
		scanf("%s", act);
		if (strcmp(act,"Enqueue")==0 || strcmp(act,"enqueue")==0) {
			int data;
			//printf("데이터입력: ");
			scanf("%d", &data);
			Enqueue(&q, data);
		}
		else if (strcmp(act, "Dequeue") == 0 || strcmp(act, "dequeue") == 0) {
			if (q.size == 0) {
				printf("큐가 텅 비어있어서 데이터 출력불가능!\n");
				continue;
			}
			printf("Dequeue(): %d\n", Dequeue(&q));
		}
		else if (strcmp(act, "show") == 0) {
			show(q);
		}
		else if (strcmp(act, "roll") == 0) {
			roll(&q);
		}
		else {
			printf("프로그램종료\n");
			break;
		}
	}

	return 0;
}