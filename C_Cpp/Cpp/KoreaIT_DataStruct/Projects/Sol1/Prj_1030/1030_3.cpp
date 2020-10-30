#include "stdio.h"
#include "stdlib.h"
#include "iostream"



void push(int data) {
	stack[++index] = data; //전위증감을 쓰면 효율적
	printf("%d push 완료\n", data);
}
int pop() { //스택배열 자료형에 맞춰서 사용
	return stack[index--]; //반환 후에 처리됨. 인덱스가 0부터 시작할 경우 전위증감을 쓸 수도 있다고 함.
}
int isFull(int index, int MAX) {
	//if (index == MAX) { 밀어넣기식으로 코딩하면 문제가 많다. 디버깅표를 좀 쓰자.. 
		//시험, 성향분석에서 이런거 많이 낸다고..
	//if (index == MAX - 1) { //배열인덱스는 MAX-1까지 존재.
	if (index == MAX) { //이게 맞는 이유가 뭘까??????
		return 1;
	}
	return 0;
}
int isEmpty() {
	//if (index == MAX) { 밀어넣기식으로 코딩하면 문제가 많다. 디버깅표를 좀 쓰자.. 
		//시험, 성향분석에서 이런거 많이 낸다고..
	if (index == -1) { //배열인덱스는 MAX-1까지 존재.
		return 1;
	}
	return 0;
}

void main() {

	int len;
	printf("스택의 크기를 입력하세요. ");
	scanf("%d", &len);
	int* stack = (int*)malloc(len*sizeof(int));
	int index = 0; //전역변수로 쓰지 않을 때에는 초기화에 유의
	//과제 1. 함수 인자 전달형태로 완성하기
	

	int act;
	while (1) {
		printf("1.push() 2.pop() 3.종료\n");
		printf("입력: ");
		scanf("%d", &act);
		if (act == 1) {
			if (isFull(index, len)) {
				printf("스택에 공간이 없습니다!\n");
				continue;
			}
			int data;
			printf("데이터를 입력해주세요: ");
			scanf("%d", &data);
			push(data);
		}
		else if (act == 2) {
			if (isEmpty()) {
				printf("데이터가 없습니다!\n");
				continue;
			}
		}
		else {
			printf("\n종료합니다...\n");
			break;
		}
	}

	return;
}
