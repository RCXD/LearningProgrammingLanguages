//��������: ����!!
//5 4 7 1 2����, ���� ���� 1�� 5�� ��ȯ
//1 _4_ 7 5 2 //4�� ���� ���� 2�� ��ȯ
//1 2 7 5 4
//1 2 _7_ 5 4 //7�� ���� ���� 4�� ��ȯ



#include "stdio.h"
#include "iostream"

//#define MYSELF
#define TEACHER
#ifdef TEACHER


void selection_sort(int* a, int len) {
	for (int x = 0; x < len; x++) {
		int min = a[x];
		int minIndex = x;
		for (int i = x + 1; i < len; i++) {
			if (min > a[i]) {
				min = a[i];
				minIndex = i;
			}
		}
		// min ���������� -> 0�� minIndex ���� ��ȯ
		int tmp = a[x];
		a[x] = a[minIndex];
		a[minIndex] = tmp;
	}
}

void main...
//���� �����...
#endif


#ifdef MYSELF
//�̿ϼ�... �Ǽ� Ȯ�ιٶ�!
int data[] = { 5, 4, 7, 1, 2 };

void main() {
	
	
	int size = sizeof(data) / sizeof(data[0]);
	for (int i = 0; i < size; i++) {
		int min = data[i];
		for (int j = i+1; j < size; j++) {
			if (min > data[j]) {
				int tmp = min;
				min = data[j];
				data[j] = tmp;
			}
		}
		for (int i = 0; i < size; i++) {
			printf("%d ", data[i]);
		}
		printf("\n");
	}

	for (int i = 0; i < size; i++) {
		printf("%d ", data[i]);
	}
	return;
}
#endif

/* �����ǥ �׸���
 *	Line
 *
 *
 *
 */