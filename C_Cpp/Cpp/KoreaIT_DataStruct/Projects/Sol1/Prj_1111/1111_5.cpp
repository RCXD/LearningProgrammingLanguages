//�ǵ��

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	int data;
	struct NODE* next;
}N;
typedef struct Queue {
	N* front;
	N* rear;
	int size; //��ȸ�� �� size�� �˰������� ȿ�����̶�� ��. �Ź� ����� ã�°ͺ�
	��, 
	//�߰��Ҷ� �ϳ��� ������Ű�� ��.
}Q;

void Enqueue(Q* q, int data) {
	if (q->size == 0) { //���⼭��, �������̹Ƿ� ->(call-by-reference?)�� �޾ƾ� �Ѵٰ� ��.

	}
}

int main() {
	Q q;
	q.front = NULL;
	q.rear = NULL;
	q.size = 0;

	Enqueue(&q, 10); //enqueue �Ŀ��� q�� ������ �ٲ��� �ϹǷ�,..


	return;
}