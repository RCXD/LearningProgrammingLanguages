#include<stdio.h>
#include<stdlib.h>
typedef struct NODE {
	int data;
	struct NODE* next;
}N;
typedef struct Queue {
	N* front;
	N* rear;
	int size;
}Q;
void Enqueue(Q* q, int data) {
	if (q->size == 0) {

	}
}
int main() {

	Q q;
	q.front = NULL;
	q.rear = NULL;
	q.size = 0;

	Enqueue(&q, 10);

	


	return 0;
}