// 1. ���� 1�� �Է� : 5
// 2. 1���� �Է��� ������ŭ ������ �Է�:
//  : 1 13 16 100 200
// 3. ����δ�, [3]

// ����1) ������������ �ԷµǾ���մϴ�.
// 1 2 5 20 10
// ����2) ������ �ԷµǸ� xxx
// [ERROR!]
#include<stdio.h>
#include<stdlib.h>
int main() {

	int n;
	printf("���� 1�� �Է�: ");
	scanf("%d", &n);
	printf("%d���� ���� �Է�: ",n);
	int *arr = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < n-1; i++) {
		if (arr[i] > arr[i + 1]) {
			printf("ERROR!\n");
			return 0;
		}
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] <0) {
			printf("ERROR!\n");
			return 0;
		}
	}

	int min =arr[1]-arr[0];
	int minIndex1, minIndex2;
	for (int i = 1; i < n-1; i++) {
		if (min > arr[i + 1] - arr[i]) {
			min = arr[i + 1] - arr[i];
		}
	}
	printf("[%d]\n", min);

	return 0;
}