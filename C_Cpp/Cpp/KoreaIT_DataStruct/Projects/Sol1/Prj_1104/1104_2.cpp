//[����] ��������, ��������, ��������, ������(���� �����ٳ�)-> �⺻!... �պ�����, ��������, ������
//�迭�� �����͸� ������������ ����(���ġ)�ϴ� �˰����� �����̶�� ��.
//����, ��� �������� �˾ƾ� ���� �� �� �ִ�. ���°� �ٰ� �ƴ�! ���� ���� Ʈ����.

//����... ���� ���°�? 
//�˻�()(==Ž��())�� ȿ�������� �ϱ� ���ؼ� ������ �Ѵ�.

//��������: �α� �����ͳ��� ���ؼ� ū���� �ڷ� ������ ������. �̰� ������ �ݺ�






#include "stdio.h"
#include "iostream"

//#define MYSELF
#define TEACHER
#ifdef TEACHER
#include <stdio.h>
void bubble_sort(int *a, int len) {
	for (int x = 0; x < len; x++) {
		for (int i = 0; i < len - 1; i++) { //����: ������ ���ں��� �Ѱ� ���� ���ؾ� �����Ⱚ�� ������ ����.
			if (a[i] > a[i + 1]) {
				//��ȯ
				int tmp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tmp;
			}
		} 
	}
}

int main() {
	int data[] = { 5, 4, 7, 1, 2 };

	printf("���� ��: ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");

	bubble_sort(data, 5); //�迭 ��ü�� ����

	printf("���� ��: ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");

	return 0;
}
#endif


#ifdef MYSELF
void main() {


	return;
}
#endif

/* �����ǥ �׸���
 *	Line
 *
 *
 *
 */