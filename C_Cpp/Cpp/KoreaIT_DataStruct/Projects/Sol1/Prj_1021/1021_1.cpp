#include "stdio.h"
#include "iostream"

//#define MYSELF
#define TEACHER
#ifdef TEACHER



//가독성 높이기!
/*
typedef struct 자료형명 {
}바꿀 이름;
*/
typedef struct stu {
    char name[10];
    int num; //번호가 꼭 필요하다. 동명이인이 있을 수도 있고.
    //즉, 값이 유일한지 판단하는 것이다.
    //프로그래밍 Tip.
    int score[2];
    double avg;
    char grade;
}S;

void show(int i) {
    printf("%d", i);
}

void show(S s) {
    printf("%d", s.num);
} //코드가 매우 짧아지고 가독성이 좋아진다!!
//C도 구조체 배우면 나쁘지 않네?
//클래스나 크게 차이 없겠지..?

void main() {

    int i = 10;
    show(i);
    S s[10]; //배열도 만들 수 있다. 자료형이니까.

    //동적 메모리 할당:
    int n;
    scanf("%d", &n);
    S s[n]; //자료형이 할 수 있는것들은 대부분 할 수 있다고
    //생각하면 된다고 한다.

    //구조체는 하나의 자료형 개념!
    //1. 함수의 인자 선언 가능
    //2. 배열 -> 구조체 배열의 개념
    //3. 배열포인터를 쓸 수 있다.
    //4. 동적 배열도 만들 수 있다.
    //struct stu s1;
    
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