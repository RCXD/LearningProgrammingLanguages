//피드백

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	int data;
	struct NODE* next;
}N;
typedef struct Queue {
	N* front;
	N* rear;
	int size; //조회할 때 size를 알고있으면 효율적이라고 함. 매번 몇개인지 찾는것보
	다, 
	//추가할때 하나씩 증가시키는 것.
}Q;

void Enqueue(Q* q, int data) {
	if (q->size == 0) { //여기서는, 포인터이므로 ->(call-by-reference?)로 받아야 한다고 함.

	}
}

int main() {
	Q q;
	q.front = NULL;
	q.rear = NULL;
	q.size = 0;

	Enqueue(&q, 10); //enqueue 후에는 q의 정보가 바뀌어야 하므로,..


	return;
}