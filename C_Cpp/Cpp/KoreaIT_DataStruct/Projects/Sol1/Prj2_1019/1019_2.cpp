#include "stdio.h"
#include "iostream"

//#define MYSELF
#define TEACHER
#ifdef TEACHER
void main() {
	int n = 0;
	printf("���� 1�� �Է�: \n");
	scanf(" %d", &n);
	printf("1���� �Է��� ������ŭ ������ �Է�: \n");
	int* arr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf(" %d", &arr[i]);
	}

	//int sw = 0;
	for (int i = 0; i < n - 1; i++) { //��ȯ�� ù���� �ڳ��� �� �� �����ؾ� �Ѵ�.
		if (arr[i] > arr[i + 1]) {
			printf("ERROR!\n");
			//sw = 1;
			return;
		}
	}
	for (int i = 0; i < n; i++) { //for���� ��ø�� ó���ӵ��� ����ؾ�������, ������ �����ٰ� �Ѵ�.
		if (arr[i] < 0) {
			printf("Error!\n");
			return;
		}
	}

	//if (sw) {
		//printf("Error!\n"); //����ġ ������ �̿��ϴ� ���.

	int res = 0;
	int min = arr[1] - arr[0];
	for (int i = 1; i < n - 1; i++) { //ó������ �ʱ�ȭ���� ó�������� ���ʿ��ϹǷ� ����
		if (min > arr[i + 1] - arr[i]) {
			min = arr[i + 1] - arr[i];
		}
	}
	printf("[%d] \n", res);

	return;
}

#endif


#ifdef MYSELF
void main() {
	while (1) {
		int num = 0;
		printf("���� 1�� �Է�: \n");
		scanf(" %d", &num);
		printf("1���� �Է��� ������ŭ ������ �Է�: \n");
		int* arr = (int*)malloc(num * sizeof(int));
		int comp = 0;
		for (int i = 0; i < num; i++) {
			scanf(" %d", &arr[i]);
			if (comp > arr[i]) { //���� ����: ���������� ���� ���� ���� ��
				printf("[ERROR! not ascending numbers]\n\n");
				continue;
			}
			else if (arr[i] < 0) {
				printf("[ERROR! Negative Integer]\n\n");
				continue;
			}
			else {
				comp = arr[i];	//�Ȱɸ��� ����
			}
		}
		if (num < 2) {
			printf("num�� �ʹ� �۽��ϴ�.\n\n");
			continue;
		}
		comp = arr[1] - arr[0]; //ù ������ �ʱ�ȭ
		int diff = 0;
		for (int i = 1; i < num - 1; i++) { //���� �ذ�
			diff = arr[i + 1] - arr[i];
			if (comp > diff) {
				comp = diff;
			}
		}
		printf("[%d]\n\n", comp);
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