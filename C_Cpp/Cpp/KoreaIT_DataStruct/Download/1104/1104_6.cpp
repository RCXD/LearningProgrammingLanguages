// 퀵 정렬
// 재귀함수==순환호출
#include<stdio.h>
int fac(int n) {
	if (n == 1) { // 종료조건 필요
		return 1;
	}
	return n*fac(n - 1);
}
int main() {

	printf("5!=%d\n", fac(5));

	return 0;
}