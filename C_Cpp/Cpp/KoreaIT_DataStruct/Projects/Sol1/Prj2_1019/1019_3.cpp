#include "stdio.h"
#include "iostream"
#include "stdlib.h" //rand(), srand()? 포함
#include "time.h" //time()함수 포함

//#define MYSELF
#define TEACHER
#ifdef TEACHER
void main() {
	//1~10 -> 10가지
	//0~9 -> 10가지
	//0~10 -> 11가지
	//rand() % 가짓수 + 시작 정수

	int lotto[5];
	srand(time(NULL)); //실행할때마다 바뀌게 하는 것
	for (int i = 0; i < 5; i++) {
		lotto[i] = rand() % 50 + 1; //변하지 않는 랜덤값임. 빌드할때마다 바뀌는 것임.
	}
	for (int i = 0; i < 5; i++) {
		printf("%d ", lotto[i]);
	}
	printf("\n");


	return;
}
//필요한건 암기할수 밖에 없다!

#endif



#ifdef MYSELF
void main() {

	return;
}
#endif

/* 디버깅표 그리기
 *	Line
 *
 *
 *
 */