#include "stdio.h"
#include "stdlib.h"
#include "iostream"



//#define MYSELF
#define TEACHER
#ifdef TEACHER
// [스택] vs [큐]
// 스택: 한쪽끝에서만 자료를 넣거나 뺄수있는 선형구조
//  최근방문한 웹페이지, 실행취소
//  후입선출==선입후출==FILO==LIFO
//  push() pop()
// -> "배열"
#include<stdio.h>
#define MAX 5
int stack[MAX];
int index = -1; // stack에 데이터가 존재하지않는다!
int isFull() {
	if (index == MAX - 1) { // ☆
		return 1;
	}
	return 0;
}
int isEmpty() {
	if (index < 0) {
		return 1;
	}
	return 0;
}
void push(int data) {
	stack[++index] = data;
	printf("%d push()완료!\n", data);
}
int pop() {
	return stack[index--];
}
int main() {

	int act;
	while (1) {
		printf("1.push() 2.pop() 3. peak() 4. size() 5.종료\n"); //configure()라는 함수... ?? 내부원소 다 확인?
													 //peak은 pop과 달리 삭제 없이 인덱스의 원소만 알려줌.
													//데이터 없으면 peak 수행
		printf("입력: ");
		scanf("%d", &act);
		if (act == 1) {
			if (isFull()) {
				printf("스택에 공간이 없습니다!\n");
				continue;
			}
			printf("정수입력: ");
			int data;
			scanf("%d", &data);
			push(data);
		}
		else if (act == 2) {
			if (isEmpty()) {
				printf("스택에 데이터가 없습니다!\n");
				continue;
			}
			printf("pop()수행! [%d]\n", pop());
		}
		else if (act == 3) {
		}

		else if (act == 4) {
			printf("현재 스택에 %d개 존재합니다.\n", index+1); //index+1! 디버깅표..
		}
		else {
			printf("\n종료합니다...\n");
			break;
		}
	}

	return 0;
}
//마무리 바람!
#endif
#ifdef TEACHER2 //복구, 오류해결 바람!
//main()에서 스택을 구현하면 함수의 크기가 커진다고 한다.
//전역변수로 구현이 효율적.

#define MAX 100 //배열 쓸때는 기호상수가 효율적
int stack[MAX];
int index = -1; //스택이 어디까지 쌓였는지 알려줄 인덱스
//초기값을 -1로. 배열인덱스와 다른 값으로.

void push(int data) {
	stack[++index] = data; //전위증감을 쓰면 효율적
	printf("%d push 완료\n", data);
}
int pop() { //스택배열 자료형에 맞춰서 사용
	return stack[index--]; //반환 후에 처리됨. 인덱스가 0부터 시작할 경우 전위증감을 쓸 수도 있다고 함.
}
int isFull() {
	//if (index == MAX) { 밀어넣기식으로 코딩하면 문제가 많다. 디버깅표를 좀 쓰자.. 
		//시험, 성향분석에서 이런거 많이 낸다고..
	if (index == MAX - 1) { //배열인덱스는 MAX-1까지 존재.
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
	int act;
	while (1) {
		printf("1.push() 2.pop() 3.종료\n");
		printf("입력: ");
		scanf("%d", &act);
		if (act == 1) {
			if (isFull()) {
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

#endif


#ifdef MYSELF
void main() {


	return;
}
#endif

/* 디버깅표 그리기
 *	Line
 * index -1 0 1 2 3 ... MAX
 *		 dt	dtdtdtdt ...dt
 *
 */