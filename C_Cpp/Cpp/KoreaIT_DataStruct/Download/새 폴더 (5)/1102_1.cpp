// ť
// ���Լ���==FIFO
// ���μ��� ����,��⿭,�ð� ���� ó�� ��
// Enqueue(),Dequeue()
#include<stdio.h>
#define MAX 5
int queue[MAX];
int s = 0;
int e = 0;
int isFull() {
	if (s == e && queue[e]!=0) {
		return 1;
	}
	return 0;
}
int isEmpty() {
	if (s == e && queue[e] == 0) {
		return 1;
	}
	return 0;
}
void Enqueue(int data) {
	queue[e++] = data;
	if(e == MAX){
		// 1. e==MAX  2. e==MAX+1  3. e==MAX-1
		e = 0;
	}
	// [ 10 20 1 2 3 ]
	//  es            
}
void Dequeue() {
	printf("Dequeue(): %d\n", queue[s]);
	queue[s++] = 0;
	if (s == MAX) { // ��
		s = 0;
	}
}
void show() {
	for (int i = 0; i < MAX; i++) {
		printf("%-3d", queue[i]);
	}
	printf("\ns=%-2d,e=%-2d\n",s,e);
}
int size() {
	if (isEmpty()) {
		return 0;
	}
	else if (isFull()) {
		return MAX;
	}
	else if (e-s<0) { // e<s
		return e - s + MAX;
	}
	else {
		return e - s;
	}
}
int main() {

	int n;
	printf("ť�� ũ�⸦ �Է�: ");
	scanf("%d", &n);
	int *q = (int *)malloc(n * sizeof(int));
	int f = 0;
	int r = 0;

	int act;
	while (1) {
		printf("1.Enqueue() 2.Dequeue() 3.show() 4.size() 5.front() 6.rear() 7.����\n");
		// front(): ���� ���� ������ �����͸� ��¸�(����xxx)
		// rear(): ���� �������� ������ �����͸� ��¸�(����xxx)
		printf("��ȣ�Է�: ");
		scanf("%d", &act);
		if (act == 1) {
			if (isFull()) {
				printf("ť�� �������� �������ԷºҰ���!\n");
				continue;
			}
			printf("�������Է�: ");
			int data;
			scanf("%d", &data);
			Enqueue(data);
		}
		else if (act == 2) {
			if (isEmpty()) {
				printf("ť�� �� �� ��������ºҰ���!\n");
				continue;
			}
			Dequeue();
		}
		else if (act == 3) {
			printf("show()ȣ��!\n");
			show();
		}
		else if (act == 4) {
			printf("size()ȣ��! %d\n", size());
		}
		else if (act == 5) {
			if (isEmpty()) {
				printf("ť�� �� �� ��������ºҰ���!\n");
				continue;
			}
			printf("front: %d\n", queue[s]);
		}
		else if (act == 6) {
			if (isEmpty()) {
				printf("ť�� �� �� ��������ºҰ���!\n");
				continue;
			}
			if (e == 0) { // e==0 ? queue[MAX - 1] : queue[e - 1]
				printf("rear: %d\n", queue[MAX - 1]);
			}
			else {
				printf("rear: %d\n", queue[e - 1]);
			}
		}
		else {
			printf("���α׷�����...\n");
			break;
		}
	}

	return 0;
}