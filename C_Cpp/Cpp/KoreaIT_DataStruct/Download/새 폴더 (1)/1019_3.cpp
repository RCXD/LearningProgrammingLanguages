// 1. 정수 1개 입력 : 5
// 2. 1에서 입력한 정수만큼 데이터 입력:
//  : 1 13 16 100 200
// 3. 결과로는, [3]

// 조건1) 오름차순으로 입력되어야합니다.
// 1 2 5 20 10
// 조건2) 음수가 입력되면 xxx
// [ERROR!]
#include<stdio.h>
#include<stdlib.h>
int main() {

	int n;
	printf("정수 1개 입력: ");
	scanf("%d", &n);
	printf("%d개의 정수 입력: ",n);
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