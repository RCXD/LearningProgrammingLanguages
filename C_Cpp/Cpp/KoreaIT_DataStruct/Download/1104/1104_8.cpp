// �� ����
// "�ǹ�"(==�Ǻ�==pivot): ����
// ����(Divide) -> ����,����(Conquer) -> ����,�պ�(Combine)
// ���ļӵ��� ����
// 3 5 7 9 1 10 6 2 8 4
#include<stdio.h>
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
int search(int* data, int len, int num) {
	// ����Ž��==�����˻�
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
	// ������ 10�� �������� ����
	// ���ϴ� �� ����ڰ� �Է��ϸ�, �ε�����ġ �˷���!
	// [?]�� �ֽ��ϴ�. VS �ش絥���;���!

	int data[] = { 3,5,7,9,1,10,6,2,8,4 };



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
	printf("���Է�: ");
	int n;
	scanf("%d", &n);
	int res = search(data, 10,n);
	if (res == -1) {
		printf("�ش絥���;���!\n");
	}
	else {
		printf("%d�� [%d]�� ����!\n", n, res);
	}

	return 0;
}