#include<stdio.h>
#include<stdlib.h>
int main() {

	// 동적 메모리 할당
	int n;
	scanf("%d", &n);
	//int arr[n];
	int *arr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	free(arr);

	// 포인터는...
	// 1. 주소를 받는 자료형이다.
	// 2. 선이다.(주소를 가리키는 자료형)

	return 0;
}