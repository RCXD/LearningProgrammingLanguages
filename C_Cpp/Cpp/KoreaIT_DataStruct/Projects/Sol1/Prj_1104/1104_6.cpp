//������!
//����Լ� Ȱ��(��ȯȣ��)

#include<stdio.h>



/*
int fac(int n) {
	//�������� �ʿ�
	if (n == 1) {
		return 1;
	}
	return n * fac(n - 1);
}


int main() {
	printf("5!=%d\n", fac(5));

	return 0;
}
*/

//�������� ���ļӵ��� ����
//����(Divide)->����: ����(Conquer) -> ����, �պ�(Combine)... ����, �պ��� ����? ���ͳݿ��� ã�ƺ���.,..
//3 5 7 9 1 10 6 2 8 4
//3�� Pivot, 5�� L, 4�� R
//L�� 3���� ���� ������ stop / R�� 3���� ũ�� ������ stop
//��� stop�Ǹ� L�� R�� ��ȯ�ϰ�, �ٽ� ������ �̵�(�����鼭)
//L�� R�� �����Ǹ� ���� ����, Pivot�� R�� ��ȯ
//R�� ���ο� Pivot, Pivot �¿츦 �����ϰ� �ٽ� ����


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int l, int r) {
	int tmp = a[l];
	a[l] = a[r];
	a[r] = tmp;
}
void quick_sort(int* a, int start, int end) {
	int pivot = a[start];
	int L = start + 1;
	int R = end;
	while (L <= R) {
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
	if (start < end) {//�迭ũ�Ⱑ 1���� �� ������ �ݺ�
		swap(a, start, R);
		quick_sort(a, start, R - 1); //��� ȣ��
		quick_sort(a, R + 1, end);
	}
}

void search() {
	//�˻��Լ� ����!
}

#define MAX 10
int main()
{
	//������ 10�� �������� ����
	srand((unsigned int)time(NULL));
	
	int a[MAX];
	for (int i = 0; i < MAX; i++) {
		a[i] = rand() % 10;
	}
	for (int i = 0; i < 10; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	//���ϴ� �� ����ڰ� �Է��ϸ� �ε��� ��ġ�� �˷���
	//�� �ȵ���? ������...???
	printf("���ϴ� �� �Է�: ");
	int input;
	scanf("%d ", &input);
	quick_sort(a, 0, 9);
	int ans = -1;
	for (int i = 0; i < MAX; i++) {
		if (input == a[i]) {
			ans = a[i];
			printf("%d�� %d �ε����� �ֽ��ϴ�.", input, i);
			break;
		}
	}
	if (ans == -1) printf("�ش� ������ ����!");
	//[?]�� �ֽ��ϴ� vs �ش� ������ ����!

	int data[] = { 3, 5, 7, 9 ,1, 10, 6, 2, 8 ,4 };
	printf("���� ��:");
	for (int i = 0; i < 10; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");

	quick_sort(data, 0, 9);

	printf("���� ��:");
	for (int i = 0; i < 10; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");
}