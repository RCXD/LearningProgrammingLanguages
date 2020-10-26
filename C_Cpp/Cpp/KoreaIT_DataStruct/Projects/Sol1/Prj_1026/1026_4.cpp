#include "stdio.h"
#include "iostream"

//#define MYSELF
#define TEACHER
#ifdef TEACHER


//공용체
//구조체와 비교하기
/*
struct stu {
	char name[10];
	int num;
};
*/

//공용체: 전체 byte를 멤버 중 공간이 가장 큰 멤머에게 맞춰주는, 
//			구조체를 생성하는 키워드
typedef union{
	int i; //4바이트... 가장 큰 공간을 가짐
	char c; //1바이트
}u;
void main() {
	
	//u aaa = { 65, 'A' }; 구조체처럼 초기화할 수 없다.
	u aaa;
	aaa.i = 65;
	aaa.c = 'A';
	printf("%d %c\n", aaa.i, aaa.c);

	aaa.i = 97; //소문자 a를 의미하는 값. c가 A에서 a로 바뀌었다.
	printf("%d %c\n", aaa.i, aaa.c);

	//한 멤버만 바꿨는데 다른 멤버도 바뀌었다.
	//단점: 정보 손실이 일어난다고 볼 수 있다.
	//장점: 메모리공간을 많이 아낄 수 있다.

	//시험문제 아니고서는 안써서 어디에 쓰는지 강사도 모른다나. 알고리즘에도 딱히 필요없나본듯?
	//포맷(%~)만 바꿔도 자료형이 바뀌므로 굳이 공용체를 쓸 필요 없다고.
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
 *
 *
 *
 */