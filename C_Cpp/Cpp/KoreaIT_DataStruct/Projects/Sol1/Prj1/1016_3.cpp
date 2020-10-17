#include "stdio.h"
#include "iostream"

/* Title : Pointer */


//#define MYSELF
#define TEACHER
#ifdef TEACHER
void swap_p(int* a, int* b) { //���� ����� main()���� ������ ���� ��
	int tmp = *a; //* ������ �׳� �ּҰ���
	*a = *b;
	*b = tmp;
}

void show(int* arr) { //�Լ��� ���ڷ� �迭�� ���� ��
	for (int i = 0; i < 3; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
#ifdef MYSELF
void f(int *arr, int *max) { //Mission
	//int len = sizeof arr / sizeof arr[0];
	int len = sizeof arr;
	//printf("%d\n", len);
	//printf("%d\n", sizeof arr);
	//printf("%d\n", sizeof arr[0]);
	*max = arr[0];
	for (int i = 0; i < len; i++) {
		if (arr[i] > *max) *max = arr[i];
	}
}
#endif
#ifndef MYSELF
void f(int *arr, int *a, int len) {
	//�ִ밪 ã�� �˰���
	//�˰��� �ش��� ã�� ������, �׸��� ���� �׸��� �����϶�!
	//printf("%d\n", sizeof(arr)); //��������. �׳� int�� ũ��.
	int max = arr[0];
	for (int i = 1; i < len; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	*a = max; //�������� �������ִ°� �� ���ڴ�. ������ �����ϸ�.
	printf("max = %d\n", max);
}
#endif

void swap(int a, int b) {
	int tmp = a;
	a = b;
	b = tmp;
	//a, b�� ���� �ٲ��� ����. �ּҰ��� �޾ƿ��� �ʱ� ����
}

void main() {
	/*
	int x = 10;
	int y[] = { 1, 2, 3 };
	printf("%d %d %d\n\n", sizeof(x), sizeof(y), sizeof(y[0]));
	printf("y �迭�� ũ��� %d�Դϴ�.\n", sizeof(y)/sizeof(y[0]));

	printf("\n\n");
	*/

	/* Mission */
	int arr_2[] = { 17, 4, 99, 25, 33 };
	//printf("%d\n", sizeof arr_2); //�������� �迭 ũ��(�迭 ���� * �ڷ��� ũ��)
	//printf("%d\n", sizeof arr_2[0]); //�������� �迭 1���� �ڷ����� ũ��
	int max = 0;
#ifdef MYSELF
	f(arr_2, &max);
#endif
#ifndef MYSELF
	f(arr_2, &max, sizeof(arr_2)/sizeof(arr_2[0])); //���⼭ �迭ũ�⸦ ��������ϳ�... ��.
#endif
	printf("arr�迭���� ���� ū ���� %d�Դϴ�.\n", max);
	printf("\n");
	/* end of mission*/

	int a = 10;
	int b = 20;
	//��ȯ �˰���
	//a = b; �׳� ������ a�� ������� ������ ����.
	int tmp = a;
	a = b;
	b = tmp;
	printf("a = %d b = %d\n", a, b);
	swap(a, b);
	printf("a = %d b = %d\n", a, b); //�ȹٲ�
	swap_p(&a, &b);
	printf("a = %d b = %d\n", a, b); //�ٲ�. ���Ͼ��� ó���ϰ������ C������ �����͸� Ȱ��.

	int arr[] = { 1, 2, 3 };
	show(arr); //arr == &arr[0]�̹Ƿ�, arr�� �Ϲ� �ڷ������δ� ���� �� ����.

	return;
}

#endif


#ifdef MYSELF
void main() {


	return;
}
#endif

/* �����ǥ �׸���
 *	Line		a	b
 *				10	20
 *	a = b		20	20
 *	b = a		20	20	//�ǹ̾��� ����
 */