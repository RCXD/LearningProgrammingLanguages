#include "stdio.h"
#include "iostream"
#include<stdlib.h>

//#define MYSELF
#define TEACHER
#ifdef TEACHER
	//����
	//���� 2�� �Է� : 7 3
	//[1 2 3 4 5 6 7]
	//[1   4   5]
	//���: 3 6 2 7 5 1 4

	//5 2
	//[1 2 3 4 5] �迭 ����
	//2 4 1 5 3: �ι�° �Է��� ����ŭ '����'�ؼ� �����ϰ� �����ϴ� �ڵ� : ����
	//������ �ȵǴ� �ٸ� ���ڳ� ����(0������)�� ��ü�ϴ°͵� �ϳ��� �ع�.
	//���ѹݺ����� ���°� ���ٰ� ��.


int check(int* arr, int len) {
	for (int i = 0; i < len; i++) {
		if (arr[i] != 0) {
			return 1; // �������
		}
	}
	return 0;
}
int main() {

	int a, b;
	scanf("%d%d", &a, &b);
	int* data = (int*)malloc(a * sizeof(int));
	for (int i = 0; i < a; i++) {
		data[i] = i + 1;
	}

	int cnt = 0;
	int i = 0;
	while (check(data, a)) {
		if (data[i] == 0) {
			i++;
			if (i == a) { // �迭�̿��, �ε�������Ȯ��!!!
				i = 0;
			}
			continue;
		}
		cnt++;
		if (cnt == b) {
			printf("%d ", data[i]);
			data[i] = 0;
			cnt = 0;
		}
		i++;
		if (i == a) {
			i = 0;
		}
	}
	// ���� 2�� �Է� : 7 3
	// [1 2 3 4 5 6 7]
	//  => 3 6 2 7 5 1 4

	// 5 2
	// [1 2 3 4 5]
	//  => 2 4 1 5 3

	�迭 VS ����Ʈ

		�ε��̹��->�˻�(), Ž��()�� ����
		����, ������->����(), ����()�� �Ҹ�

		�˻�(), Ž��()�� �Ҹ�
		����(), ����()�� ����
		�������������� == ������->����ȿ���� ����

		���(NODE)
		�����ͺ� + �ּҺ�(== ��ũ��)
		�ּҺ� = > ������带 ����Ű�� �����Ͱ� ������

		return 0;
}


#endif

//���� �� ������ �迭�� �Ѱ踦 ������ ����Ʈ�� �ذ��ؾ� �ϴ� ������� ��.
#ifdef MYSELF
void main() {
	//max, sep <- input
	//max = 7, sep = 3�̸�
	//1 2 3 4 5 6 7
	//���: arr[sep(3)], arr[sep+sep(6)], arr[sep+sep+sep(2)], arr[sep+sep+sep+sep+jump+jump+(7)]
	//3 -> cnt 0
	//6 -> cnt 1
	//2 = 9%7 -> cnt 2
	//7 -> cnt 3

	int max, sep;
	printf("������ ���̿� ������ �Է��ϼ���: ");
	scanf("%d %d", &max, &sep);
	int* arr = (int*)malloc(sizeof(int) * max);
	
	for (int i = 1; i <= max; i++) {
		arr[i - 1] = i;
		printf("%d ", arr[i - 1]);
	}
	printf("\n");
	
	
	... ���� �غ���.

	return;
}
#endif

/* �����ǥ �׸���
 *	Line
 *
 *
 *
 */