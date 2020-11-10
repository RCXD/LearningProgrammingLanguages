// 1. ť ��ü ũ�������� ����.
// 2. 0���� �Է��Ҽ��ִ�.
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
	// ������

	// ������ ��带 ť�� �����ϱ�!
	if (q->size == 0) {
		// ť�� ���������,
		// �� ���� ���� ���� �����ض�.
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
	printf("show()ȣ��!\n");
	N* p = q.front;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
void roll(Q *q) {
	// �����͵��� ���������� 1ĭ�� �̵�
	// �����͵��� �������� 1ĭ�� �̵��ϴ� ȿ��
	
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
		printf("1.Enqueue() 2.Dequeue() 3.show() 4.roll() 5.����\n");
		scanf("%s", act);
		if (strcmp(act,"Enqueue")==0 || strcmp(act,"enqueue")==0) {
			int data;
			//printf("�������Է�: ");
			scanf("%d", &data);
			Enqueue(&q, data);
		}
		else if (strcmp(act, "Dequeue") == 0 || strcmp(act, "dequeue") == 0) {
			if (q.size == 0) {
				printf("ť�� �� ����־ ������ ��ºҰ���!\n");
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
			printf("���α׷�����\n");
			break;
		}
	}

	return 0;
}