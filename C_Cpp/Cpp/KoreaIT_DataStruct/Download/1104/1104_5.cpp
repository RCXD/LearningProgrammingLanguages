// 탐색()==검색()
#include<stdio.h>
#include<stdlib.h>
void selection_sort(int *a, int len) {
	for (int x = 0; x < len; x++) {
		int min = a[x];
		int minIndex = x;
		for (int i = x + 1; i < len; i++) {
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
int search(int* data,int len,int num) {
	int l = 0;
	int r = len - 1;
	int m = (l + r) / 2;
	while (1) {
		if (data[m] == num) {
			return m;
		}
		else if (data[m] < num) {
			l = m + 1;
		}
		else {
			r = m - 1;
		}
		m = (l + r) / 2;

		if (l > r) {
			return -1;
		}
	}
}
int main() {

	// 1. 7개의 정수 데이터를 랜덤으로 저장
	// (0~99)
	// 2. 정렬-> 버블,선택,삽입
	// 3. 검색하려는 데이터 입력
	// 4. [?]에 있다.
	int data[7];
	for (int i = 0; i < 7; i++) {
		data[i] = rand() % 100;
	}
	for (int i = 0; i < 7; i++) {
		printf("%3d", data[i]);
	}
	printf("\n");
	///
	selection_sort(data, 7);
	for (int i = 0; i < 7; i++) {
		printf("%3d", data[i]);
	}
	printf("\n");
	printf("검색할 데이터 입력: ");
	int num;
	scanf("%d", &num);
	printf("%d는 [%d]에 위치합니다.\n",num,search(data, 7, num));

	return 0;
}