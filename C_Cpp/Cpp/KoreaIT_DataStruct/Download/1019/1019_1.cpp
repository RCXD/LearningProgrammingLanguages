#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int * b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void show(int *arr,int len) {
	printf("show()의 size=%d\n", sizeof(arr));
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main() {
	/*
	// 포인터 = 주소를 가리키는 자료형
	int a = 10, b = 20;
	swap(&a, &b);
	printf("a=%d b=%d\n", a, b);

	int arr[] = { 1,2,3 };
	int arr2[] = { 11,22,33 };
	printf("size=%d %d\n", sizeof(arr), sizeof(arr[0]));
	show(arr2,sizeof(arr)/sizeof(arr[0]));
	// arr==&arr[0]
	*/

	int n;
	scanf("%d", &n);
	int *arr=(int *)malloc(n*sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	free(arr);

	return 0;
}