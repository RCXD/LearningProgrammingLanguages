// �� ����
// ����Լ�==��ȯȣ��
#include<stdio.h>
int fac(int n) {
	if (n == 1) { // �������� �ʿ�
		return 1;
	}
	return n*fac(n - 1);
}
int main() {

	printf("5!=%d\n", fac(5));

	return 0;
}