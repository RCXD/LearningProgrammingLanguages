#include<stdio.h>
int main() {
	
	// ������Ʈ->�Ӽ�->C->��ó����
	// _CRT_SECURE_NO_WARNINGS
	
	int a, b;
	printf("1.�ΰ��� ������ �Է�: ");
	scanf("%d%d", &a, &b);
	int res = 1;
	for (int i = 0; i < b; i++) {
		res *= a;
	}
	printf("%d�� %d�� = %d\n\n", a, b, res);

	printf("2.3���� �Ǽ��� �Է��ϼ���.\n");
	double arr[3];
	int cnt=0;
	for (int i = 0; i < 3; i++) {
		printf("%d��: ", i+1);
		scanf("%lf", &arr[i]);
		if (arr[i] < 0.0) {
			cnt++;
		}
	}
	printf("�� �� ������ %d��\n", cnt);

	return 0;
}