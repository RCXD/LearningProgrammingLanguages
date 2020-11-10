// 1.���� 2.���� 3.����

// 1) ��⿭ ť�� ��� 1���߰�
// ���: �̸�,���Ź�ȣ,��ȭ����
// � ��ȭ�� ���ðڽ��ϱ�? 2
//  [1.aaa 2.bbb 3.ccc]
// ������ �����Է�: ȫ�浿
// ���Ź�ȣ�� �������� ���� ��� 1001~9999
// "ȫ�浿��, bbb��ȭ [1234]�Դϴ�."

// 2) �������? (ť�� ������� �� ū�Է½�, �Ұ����ϴٴ� �ȳ����!)
// ȫ�浿��, ���Ź�ȣ��? 1234
// bbb ��ſ� �����Ǽ���~!!
// �Ӳ�����, ���Ź�ȣ��? 1111
// ����Ұ�!
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
char MT[MAX][30] = { "����","�ٸ���","�Ҹ���" };
void Enqueue(Q* q) {
	N* node = (N*)malloc(sizeof(N));
	node->data.data= rand() % 8999 + 1001;
	for (int i = 0; i < MAX; i++) {
		printf("%d.%s ", i + 1, MT[i]);
	}
	printf("\n� ��ȭ�� ���ðڽ��ϱ�? ");
	int num;
	scanf("%d", &num);
	num--;
	// node->data.movie = MT[num]; xxx
	strcpy(node->data.movie, MT[num]);
	// strcpy(A,B); << B�� ���ڿ����� A�� ���ڿ������� �����ϴ� �Լ�
	printf("������ �����Է�: ");
	scanf("%s", node->data.name);
	node->next = NULL;
	printf("%s��, %s��ȭ [%d]�Դϴ�.\n", node->data.name, node->data.movie, node->data.data);
	// ������

	// ť�� Enqueue()
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
	printf("%s��, ���Ź�ȣ��? ",q->front->data.name);
	scanf("%d", &n);
	if (n == q->front->data.data) {
		printf("%s ��ſ� �����Ǽ���~!!\n", q->front->data.movie);
		q->front = q->front->next;
		q->size--;
	}
	else {
		q->rear->next = q->front;
		q->front = q->front->next;
		q->rear = q->rear->next;
		q->rear->next = NULL;
		printf("����Ұ�!\n");
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
		printf("1.���� 2.���� 3.����  ");
		scanf("%d", &act);
		if (act == 1) {
			Enqueue(&q);
		}
		else if (act == 2) {
			printf("��������Ͻðڽ��ϱ�? ");
			int n;
			scanf("%d", &n);
			if (q.size < n) {
				printf("����ں��� �����ϴ�!\n");
				continue;
			}
			for (int i = 0; i < n; i++) {
				Dequeue(&q);
			}
		}
		else {
			printf("���α׷�����...\n");
			break;
		}
	}

	return 0;
}