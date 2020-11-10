#include<stdio.h>
// 공용체: 전체 byte를 멤버중 공간이 가장 큰 멤버에게 맞추는 구조체를 생성하는 키워드
typedef union uni {
	int i;
	char c;
}u;
int main() {

	//u aaa = { 65,'A' };
	u aaa;
	aaa.i = 65;
	aaa.c = 'A';
	printf("%d %c\n", aaa.i, aaa.c);

	aaa.i = 97;
	printf("%d %c\n", aaa.i, aaa.c);

	aaa.c = 'b';
	printf("%d %c\n", aaa.i, aaa.c);

	return 0;
}