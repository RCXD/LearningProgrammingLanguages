// ������
#include<stdio.h>
void swap(int *a,int *b) { // ����������Լ����� ������ ����� main()���Ե� ������ ������
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void show(int *arr) { // �Լ��� ���ڷ� �迭�� ������
	for (int i = 0; i < 3; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void f(int *arr,int *a,int len) {
	printf("%d\n", sizeof(arr));

	// [�ִ밪ã��]�˰���
	int max = arr[0];
	for (int i = 1; i < len; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	//printf("max=%d\n", max);
	*a = max;
}
int main() {
	/*
	int x = 10;
	int y[] = { 1,2,3 };
	printf("%d %d %d\n", sizeof(x), sizeof(y), sizeof(y[0]));
	printf("y�迭�� ũ��� %d�Դϴ�.\n", sizeof(y) / sizeof(y[0]));
	*/

	int arr[] = { 17,4,99,25,33 };
	int a = 0;
	f(arr,&a,sizeof(arr)/sizeof(arr[0])); // &arr[0]
	printf("arr�迭���� ����ū���� %d�Դϴ�.\n", a);

	/*
	int a = 10;
	int b = 20;
	// [��ȯ]�˰��� -> �ӽ����庯��
	swap(&a, &b);
	printf("a=%d b=%d\n", a, b);

	int arr[] = { 1,2,3 };
	show(arr); // arr==&arr[0]
	*/
	return 0;
}