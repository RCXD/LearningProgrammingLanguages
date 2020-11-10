#include<stdio.h>
// 선택정렬
void selection_sort(int *a, int len) {
	for (int x = 0; x < len; x++) {
		int min = a[x];
		int minIndex = x;
		for (int i = x+1; i < len; i++) {
			if (min > a[i]) {
				min = a[i];
				minIndex = i;
			}
		}
		// min 가장작은값 -> 0과 minIndex 값을 교환
		int tmp = a[x];
		a[x] = a[minIndex];
		a[minIndex] = tmp;
	}
}
int main() {

	int data[] = { 5,4,7,1,2 };

	printf("정렬전: ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");

	selection_sort(data, 5);

	printf("정렬후: ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");

	return 0;
}