#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main() {

	// [������ �����]
	srand(time(NULL)); // rand()ȣ������ 1�� ȣ���ص־�, real����������!
	int n = rand() % 10 + 1;
	// % 1~10 : ������==������
	// + a : a���� ����==������

	printf("%d\n", n);

	return 0;
}