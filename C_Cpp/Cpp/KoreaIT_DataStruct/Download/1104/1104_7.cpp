// �� ����
// "�ǹ�"(==�Ǻ�==pivot): ����
// ����(Divide) -> ����,����(Conquer) -> ����,�պ�(Combine)
// ���ļӵ��� ����
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
	// ������ 10�� �������� ����
	// ���ϴ� �� ����ڰ� �Է��ϸ�, �ε�����ġ �˷���!
	// [?]�� �ֽ��ϴ�. VS �ش絥���;���!

	int data[10];
	for (int i = 0; i < 10; i++) {
		data[i] = rand() % 100;
	}
	printf("������: ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");

	quick_sort(data, 0, 9); // �迭�� ����xxx -> index ����

	printf("������: ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");

	printf("�� �Է�: ");
	int n;
	scanf("%d", &n);




	return 0;
}