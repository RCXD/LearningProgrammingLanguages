#include "stdio.h"
#include "iostream"
#include "stdlib.h" //rand(), srand()? ����
#include "time.h" //time()�Լ� ����

//#define MYSELF
#define TEACHER
#ifdef TEACHER
void main() {
	//1~10 -> 10����
	//0~9 -> 10����
	//0~10 -> 11����
	//rand() % ������ + ���� ����

	int lotto[5];
	srand(time(NULL)); //�����Ҷ����� �ٲ�� �ϴ� ��
	for (int i = 0; i < 5; i++) {
		lotto[i] = rand() % 50 + 1; //������ �ʴ� ��������. �����Ҷ����� �ٲ�� ����.
	}
	for (int i = 0; i < 5; i++) {
		printf("%d ", lotto[i]);
	}
	printf("\n");


	return;
}
//�ʿ��Ѱ� �ϱ��Ҽ� �ۿ� ����!

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