// 1.예매 2.입장 3.종료

// 1) 대기열 큐에 사람 1명추가
// 사람: 이름,예매번호,영화제목
// 어떤 영화를 보시겠습니까? 2
//  [1.aaa 2.bbb 3.ccc]
// 예약자 성함입력: 홍길동
// 예매번호를 랜덤으로 지정 출력 1001~9999
// "홍길동님, bbb영화 [1234]입니다."

// 2) 몇명입장? (큐의 사이즈보다 더 큰입력시, 불가능하다는 안내출력!)
// 홍길동님, 예매번호는? 1234
// bbb 즐거운 관람되세요~!!
// 임꺽정님, 예매번호는? 1111
// 입장불가!
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 3
typedef struct Per {
	int data;
	char movie[15];
	char name[15];
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
char MT[MAX][15] = { "삼진","다만악","소리도" };
int main() {

	rand() % 8999 + 1001;

	return 0;
}