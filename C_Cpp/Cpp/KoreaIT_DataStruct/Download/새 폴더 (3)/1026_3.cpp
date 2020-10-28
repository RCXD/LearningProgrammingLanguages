#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main() {

	// [랜덤수 만들기]
	srand(time(NULL)); // rand()호출전에 1번 호출해둬야, real랜덤값가능!
	int n = rand() % 10 + 1;
	// % 1~10 : 종류수==가짓수
	// + a : a부터 시작==시작점

	printf("%d\n", n);

	return 0;
}