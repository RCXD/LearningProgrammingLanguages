#include<stdio.h>
#include<stdlib.h>
int main() {

	// ���� �޸� �Ҵ�
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

	// �����ʹ�...
	// 1. �ּҸ� �޴� �ڷ����̴�.
	// 2. ���̴�.(�ּҸ� ����Ű�� �ڷ���)

	return 0;
}