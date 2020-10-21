#include "stdio.h"
#include "iostream"
#include "stdlib.h"

#define MYSELF
//#define TEACHER
#ifdef TEACHER
#include<stdio.h>
#include<stdlib.h>
typedef struct point {
	int x;
	int y;
}P;
P f(P a, P b) {
	P res;
	res.x = (a.x + b.x) / 2;
	res.y = (a.y + b.y) / 2;
	return res;
}
void input(P* p) {

	P pp;
	printf("점의 x좌표입력: ");
	scanf("%d", &pp.x);
	printf("점의 y좌표입력: ");
	scanf("%d", &pp.y);

	*p = pp;
}
int main() {

	/*
	P p1 = { 1,1 };
	P p2;
	input(&p2);

	P p3 = f(p1, p2);
	printf("p3의 좌표는 (%d,%d)입니다.\n", p3.x, p3.y);
	*/

	int n;
	printf("점의 개수를 입력하세요.  ");
	scanf("%d", &n);
	P* p = (P*)malloc(n * sizeof(P));
	for (int i = 0; i < n; i++) {
		printf("%d번 점의 x좌표입력: ", i + 1);
		scanf("%d", &p[i].x);
		printf("%d번 점의 y좌표입력: ", i + 1);
		scanf("%d", &p[i].y);
		printf("p%d(%d,%d)\n\n", i + 1, p[i].x, p[i].y);
	}
	int x = 0, y = 0;
	for (int i = 0; i < n; i++) {
		x += p[i].x;
		y += p[i].y;
	}
	printf("x좌표의 합은 %d이고, y좌표의 합은 %d입니다.\n", x, y);


	return 0;
}

#endif


#ifdef MYSELF




typedef struct point {
	int x;
	int y;
}P;

P f(P a, P b) { //구조체는 자료형에 불과! 반환값으로도 쓸 수 있는 것.
	P res;
	res.x = (a.x + b.x) / 2;
	res.y = (a.y + b.y) / 2;
	return res;
}

void input(P* p) { //일부러 포인터를 쓰려고 만드는 함수라고 함. 효율적이진 않다고 함!
	P pp;
	printf("점의 x좌표 입력: ");
	scanf("%d", &pp.x);
	printf("점의 y좌표 입력: ");
	scanf("%d", &pp.y);

	*p = pp;
}

void main() {
	P p1 = { 1, 1 };
	P p2;
	input(&p2);
	/*
	printf("p2의 x좌표 입력: ");
	scanf(" %d", &p2.x);
	printf("p2의 y좌표 입력: ");
	scanf(" %d", &p2.y);
	*/

	//p1과 p2의 중앙점을 찾아 p3에 넣어라
	/*
	P p3 = { (p1.x + p2.x) / 2, (p1.y + p2.y) / 2 };
	*/
	P p3 = f(p1, p2);
	printf("중앙점 : { %d, %d }\n", p3.x, p3.y);


	//입력부
	int n;
	printf("점의 개수를 입력하세요. ");
	scanf("%d", &n);
	P* p = (P*)malloc(sizeof(P) * n);
	for (int i = 0; i < n; i++) {
		printf("%d번 점의 x좌표 입력: ", i + 1);
		scanf("%d", &p[i].x);
		printf("%d번 점의 y좌표 입력: ", i + 1);
		scanf("%d", &p[i].y);
		printf("p%d(%d, %d)\n\n", i + 1, p[i].x, p[i].y);
	}
	// 입력부, 수행부, 출력부를 구분하자.
	//수행부
	int x = 0, y = 0;
	for (int i = 0; i < 3; i++) {
		x += p[i].x;
		y += p[i].y;
	}
	//출력부
	printf("x좌표의 합: %d\n", x);
	printf("y좌표의 합: %d\n", y);


	return;
}


/* FAQ
구조체와 클래스의 큰 차이점!
클래스는 멤버함수(메소드)를 만들 수 없다.
*/
#endif

/* 디버깅표 그리기
 *	Line
 *
 *
 *
 */