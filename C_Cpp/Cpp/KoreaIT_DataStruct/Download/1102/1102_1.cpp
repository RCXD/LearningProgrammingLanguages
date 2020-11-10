// 큐
// 선입선출==FIFO
// 프로세스 관리,대기열,시간 순서 처리 등
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
	if (s == MAX) { // ☆
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
	printf("큐의 크기를 입력: ");
	scanf("%d", &n);
	int *q = (int *)malloc(n * sizeof(int));
	int f = 0;
	int r = 0;

	int act;
	while (1) {
		printf("1.Enqueue() 2.Dequeue() 3.show() 4.size() 5.front() 6.rear() 7.종료\n");
		// front(): 가장 먼저 저장한 데이터를 출력만(삭제xxx)
		// rear(): 가장 마지막에 저장한 데이터를 출력만(삭제xxx)
		printf("번호입력: ");
		scanf("%d", &act);
		if (act == 1) {
			if (isFull()) {
				printf("큐가 가득차서 데이터입력불가능!\n");
				continue;
			}
			printf("데이터입력: ");
			int data;
			scanf("%d", &data);
			Enqueue(data);
		}
		else if (act == 2) {
			if (isEmpty()) {
				printf("큐가 텅 비어서 데이터출력불가능!\n");
				continue;
			}
			Dequeue();
		}
		else if (act == 3) {
			printf("show()호출!\n");
			show();
		}
		else if (act == 4) {
			printf("size()호출! %d\n", size());
		}
		else if (act == 5) {
			if (isEmpty()) {
				printf("큐가 텅 비어서 데이터출력불가능!\n");
				continue;
			}
			printf("front: %d\n", queue[s]);
		}
		else if (act == 6) {
			if (isEmpty()) {
				printf("큐가 텅 비어서 데이터출력불가능!\n");
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
			printf("프로그램종료...\n");
			break;
		}
	}

	return 0;
}