#include "stdio.h"
#include "iostream"
#include "stdlib.h"
#include "time.h"

#define MYSELF
//#define TEACHER
#ifdef TEACHER
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void inputNum(int* p) {
	int num;
	printf("복권의 수는 몇개입니까?  ");
	scanf("%d", &num);
	*p = num;
}
void show(int* data, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");
}
int main() {

	int num;
	inputNum(&num);
	int* lotto = (int*)malloc(num * sizeof(int));
	srand(time(NULL));
	for (int i = 0; i < num; i++) {
		lotto[i] = rand() % 50 + 1;
   }
	show(lotto, num);

	// 5
	// 1 2 3 4 5 << 컴퓨터가 설정!
	// 3점 축하합니다!

	// 만약, 복권의 수가 홀수라면 +1점 득점
	// num=5 -> 3개이상 [축하합니다!]
	// num=10 -> 5개이상 [축하합니다!]

	// 점수만들기 수행
	int point = 0;
	for (int i = 0; i < num; i++) {
		if (lotto[i] % 2) { // lotto[i] % 2 == 1
			point++;
		}
	}
	printf("%d점! ", point);
	if (num / 2 <= point) { //조건 둘다 부합하니 이게 더 좋은거다...!
		printf("축하합니다!");
	}
	printf("\n");

	return 0;
}


#endif


#ifdef MYSELF
void inputNum(int* num) { //코딩 수정필요. num 엑세스
	int input;
	printf("복권의 수는 몇개입니까?  ");
	scanf(" %d", &input);
	*num = input;
} //반환하는 값이 1개이면 함수 반환값으로 처리하는게 낫다.
void show(int* data, int size) { //복권값 보여주기
	for (int i = 0; i < size; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");
}

void main() {
	while (1) {
		int num;
		inputNum(&num);
		if (num == 99) break; //탈출!
		int* lotto = (int*)malloc(num * sizeof(int));

		int cntOdd = 0;
		srand(time(NULL)); //실행할때마다 바뀌게 하는 것
		for (int i = 0; i < num; i++) {
			lotto[i] = rand() % 50 + 1; //변하지 않는 랜덤값임. 빌드할때마다 바뀌는 것임.
			//1~50의 무작위 수
			if (lotto[i] % 2) cntOdd++; //홀수 조건 : %2 == 1
		}

		if (num == 5 && cntOdd >= 3) printf("축하합니다!\n");
		else if (num == 10 && cntOdd >= 5) printf("축하합니다!\n");
		show(lotto, num);

		//만약 복권의 수가 홀수라면 +1점 득점
		//num = 5  -> 3개 이상 [축하합니다!] //홀수가 5개중 3개 이상이면
		//num = 10 -> 5개 이상 [축하합니다!] //홀수가 10개 중 5개 이상이면
	}
	return;
}
#endif

/* 디버깅표 그리기
 *	Line
 *	
 *
 *
 */