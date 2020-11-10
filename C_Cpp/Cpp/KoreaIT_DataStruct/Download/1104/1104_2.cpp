// [정렬]: 버블 삽입 선택 퀵 합병 도수 셀 ...
// 배열의 데이터를 오름차순으로 재배치하는 알고리즘
// "검색()(==탐색())"을 효율적으로 하기위해서 정렬을 한다!
#include<stdio.h>
void bubble_sort(int *a, int len) {
	for (int x = 0; x < len; x++) {
		for (int i = 0; i < len - 1; i++) {
			if (a[i] > a[i + 1]) {
				// [교환]
				int tmp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tmp;
			}
		}
	}
}
int main() {

	int data[] = { 5,4,7,1,2 };

	printf("정렬전: ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");

	bubble_sort(data,5); // data==&data[0]

	printf("정렬후: ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");

	return 0;
}