#include<stdio.h>
// ����ü: ��ü byte�� ����� ������ ���� ū ������� ���ߴ� ����ü�� �����ϴ� Ű����
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