// 퀵 정렬
// "피벗"(==피봇==pivot): 기준
// 분할(Divide) -> 정복,정렬(Conquer) -> 결합,합병(Combine)
// 정렬속도가 빠름
// 3 5 7 9 1 10 6 2 8 4
#include<stdio.h>
#include<stdlib.h>
void swap(int* a, int l, int r) {
	int tmp = a[l];
	a[l] = a[r];
	a[r] = tmp;
}
void quick_sort(int *a, int start, int end) {
	int pivot = a[start];
	int L = start + 1;
	int R = end;
	while (L <= R) { // 
		while (a[L] < pivot) {
			L++;
		}
		while (a[R] > pivot) {
			R--;
		}
		if (L <= R) {
			swap(a, L, R);
		}
	}
	if (start<end) { //
		swap(a, start, R);
		quick_sort(a, start, R - 1); //
		quick_sort(a, R + 1, end);
	}
}
int main() {
	// 데이터 10개 랜덤으로 저장
	// 원하는 값 사용자가 입력하면, 인덱스위치 알려줌!
	// [?]에 있습니다. VS 해당데이터없음!

	int data[10];
	for (int i = 0; i < 10; i++) {
		data[i] = rand() % 100;
	}
	printf("정렬전: ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");

	quick_sort(data, 0, 9); // 배열의 길이xxx -> index 범위

	printf("정렬후: ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");

	printf("값 입력: ");
	int n;
	scanf("%d", &n);




	return 0;
}