#include "stdio.h"
#include "iostream"

#define TEACHER
#ifdef TEACHER
void main() {
	int a, b;
	printf("1. 2���� ������ �Է�: ");
	scanf("%d %d", &a, &b);
	int res = 1;
	for (int i = 1; i <= b; i++) {
		res *= a; //1���� b����, �� b������ŭ �����ָ� �װ� ������.
	} //Lecture : �ݺ�Ƚ���� �ָ��ϸ� while�� ���
	printf("%d�� %d�� = %d\n\n", a, b, res);

	double arr[3];
	int cnt=0; //������ ������ ���� �� ����
	printf("2, 3���� �Ǽ��� �Է��ϼ���.\n"); //���ñ� ��� �����µ�, �ϴ� ��ŵ. �����ڵ� ����
	for (int i = 0; i < 3; i++) {
		printf("%d��:", i + 1);
		scanf("%lf", &arr[i]);
		if (arr[i] < 0.0) {
			cnt++;
		}
	}
	printf("�� �� ������ %d��\n", cnt);

	return;
}

#endif


#ifdef MYSELF
int in1, in2 = 0;
float inf1, inf2, inf3 = 0;

void main() {
	//������Ʈ -> �Ӽ� -> C -> ��ó����
	//_CRT_SECURE_NO_WARNINGS
	//������ : https://stackoverflow.com/questions/16883037/remove-secure-warnings-crt-secure-no-warnings-from-projects-by-default-in-vis

	printf("1. 2���� ������ �Է�: ");
	scanf("%d%d", &in1, &in2); //scanf_s�� ������� ����. VCpp�� �Ǵ°��̴� �߸��ȰŶ�� ��.
	printf("\n%d�� %d�� = %d\n\n", in1, in2, (int)powf(in1, in2));

	printf("2, 3���� �Ǽ��� �Է��ϼ���.");
	scanf("%f%f%f", &inf1, &inf2, &inf3);
	printf("\n1�� : %1.1f", inf1);
	printf("\n2�� : %1.1f", inf2);
	//...


	return;
}
#endif

/* �����ǥ �׸���
 *	Line	a	b	res	i
 *			10	2	1	0
 *					10	1
 *					100	2
 */